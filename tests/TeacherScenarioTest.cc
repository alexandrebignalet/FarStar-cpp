#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/HybridShip.h"
#include "../include/Phaser.h"
#include "../include/Blaster.h"
#include "../include/Container.h"
#include "../include/LightWeightWarShip.h"

using testing::Eq;
using testing::Types;
using testing::Test;

//soit un vaisseau de combat léger VC-1 (volume=10, masse=50, 2 armes max)
//on équipe VC-1 avec deux phasers (volume=1, masse=1)
//soit un vaisseau de transport VT-2 (volume=100, masse=100, cap_volume=90, cap_masse=300)
//on charge VT-2 avec 5 conteneurs (volume=1, masse=1)
//on charge VT-2 avec VC-1
//on déséquipe un des phasers de VC-1 et on le charge dans VT-2 comme du fret
//soit MR-63 un vieux modèle de vaisseau de transport lourd capable de se battre (volume=200, masse=150, cap_volume=180, cap_masse=600, 5 armes max)
//on équipe MR-63 avec deux blasters (volume=2, masse=2, gaz=50%), deux phasers (volume=1, masse=1), le vaisseau VT-2, et 4 conteneurs (volume=10, masse=100)
//on veut savoir quelle est la masse totale de MR-63 (un bon gros 713) et quel est le volume disponible dans MR-63 (il en reste pour 34)
//on veut savoir où est chacun des phasers (deux sont dans MR-63, un est dans la soute de VT-2, le dernier est équipé par VC-1 qui est dans la soute de VT-2)
//on veut connaitre le niveau de gaz des blasters équipés par MR-63, puis les recharger

class TeacherScenarioTest : public Test {
protected:
    virtual void SetUp() {

        this->vc1 = new LightWeightWarShip(10, 50, 2);
        cout << "Soit un vaisseau de combat léger "
             << this->vc1->getName()
             << "(volume=10, masse=50, 2 armes max)"
             << endl;

        cout << "On équipe "
             << this->vc1->getName()
             << " avec deux phasers (volume=1, masse=1)"
             << endl;

        Phaser *p1 = new Phaser(1,1);
        Phaser *p2 = new Phaser(1,1);

        vc1->load(p1);
        vc1->load(p2);

        this->phasers.push_back(p1);
        this->phasers.push_back(p2);

        this->vt2 = new TransportShip(100, 100, 90, 300);
        cout << "soit un vaisseau de transport "
             << this->vt2->getName()
             << " (volume=100, masse=100, cap_volume=90, cap_masse=300)"
             << endl;

        cout << "on charge "
             << this->vt2->getName()
             << " avec 5 conteneurs (volume=1, masse=1)"
             << endl;

        Container *c;
        for ( int unsigned i = 0 ; i < 5 ; i ++) {
            c = new Container(1,1);
            this->vt2->load(c);
        }

        cout << "on charge "
             << this->vt2->getName()
             << " avec "
             << this->vc1->getName()
             << endl;
        this->vt2->load(this->vc1);

        cout << "on déséquipe un des phasers de "
             << this->vc1->getName()
             << " et on le charge dans "
             << this->vt2->getName()
             << " comme du fret"
             << endl;

        this->vc1->unload(p1);
        this->vt2->load(p1);

        this->mr63 = new HybridShip(200, 150, 180, 600, 5);
        cout << "soit " << this->mr63->getName()
             << " un vieux modèle de vaisseau de transport lourd capable de se battre (volume=200, masse=150, cap_volume=180, cap_masse=600, 5 armes max)"
             << endl;


        cout << "on équipe "
             << this->mr63->getName()
             << " avec deux blasters (volume=2, masse=2, gaz=50%), deux phasers (volume=1, masse=1), le vaisseau "
             << this->vt2->getName() << ", et 4 conteneurs (volume=10, masse=100)"
             << endl;

        Blaster *b1 = new Blaster(2,2,50);
        Blaster *b2 = new Blaster(2,2,50);

        this->mr63->load(b1);
        this->mr63->load(b2);

        Phaser *p3 = new Phaser(1,1);
        Phaser *p4 = new Phaser(1,1);

        this->phasers.push_back(p3);
        this->phasers.push_back(p4);

        this->mr63->load(p3);
        this->mr63->load(p4);
// TODO implement load method in ship, redef in transport calling the parent and adjusting vc and wc , redef in warship adding constraints adn setequipped(true)
        //TODO in hybrid redef and using one or the other according on param type but how could we know if it's for equip or to load??
        this->mr63->load(this->vt2);

        for ( int unsigned i = 0 ; i < 4 ; i ++) {
            c = new Container(10, 100);
            this->mr63->load(c);
        }

        cout << "on veut connaitre le niveau de gaz des blasters équipés par " << this->mr63->getName() << ", puis les recharger" << endl;
        for ( int unsigned i = 0 ; i < this->mr63->getEquipments().size() ; i++) {
            Blaster *b = dynamic_cast<Blaster*>(this->mr63->getEquipments()[i]);
            if (b != NULL) {
                cout << "Niveau de gaz de " << b->getName() << ": " << b->getGazLevel() << endl;
                b->recharge();
                cout << "Niveau de gaz de " << b->getName() << " après rechargement: " << b->getGazLevel() << endl;
            }
        }
    }

    void resolveLocation(Equipment* equipment) {
        if ( equipment->getLocation() == NULL ) {
            return;
        }

        if ( dynamic_cast<Weapon*>(equipment) != NULL && dynamic_cast<Weapon*>(equipment)->isEquipped() ) {
            cout << equipment->getName() << " equipped by " << equipment->getLocation()->getName() << endl;
        } else {
            cout << equipment->getName() << " loaded in " << equipment->getLocation()->getName() << endl;
        }

        this->resolveLocation(equipment->getLocation());
    }

    // virtual void TearDown() {}
    vector<Phaser*> phasers;
    HybridShip *mr63;
    LightWeightWarShip *vc1;
    TransportShip *vt2;
};

TEST_F(TeacherScenarioTest, mr_63_get_mass_get_volume_capacity_remaining_and_get_location_of_his_phasers) {

    cout << "on veut savoir quelle est la masse totale de "
         << this->mr63->getName()
         << " (un bon gros 713) et quel est le volume disponible dans MR-63 (il en reste pour 34)"
         << endl;

    cout << "Masse de "
         <<this->mr63->getName()
         <<": "
         << this->mr63->getMass()
         << endl;

    cout << "Volume disponible de "
         <<this->mr63->getName()
         <<": "
         << this->mr63->getVolumeCapacityRemaining()
         << endl;

    cout << "on veut savoir où est chacun des phasers (deux sont dans "
         << this->mr63->getName()
         << ", un est dans la soute de "
         << this->vt2->getName()
         << ", le dernier est équipé par "
         << this->vc1->getName()
         << " qui est dans la soute de "
         << this->vt2->getName()
         << ")" << endl;

    for ( int unsigned i = 0 ; i < this->phasers.size() ; i++ ) {
        this->resolveLocation(this->phasers[i]);
    }
}