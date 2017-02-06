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
        vector<Phaser*> phasers;

        cout << "Soit un vaisseau de combat léger VC-1 (volume=10, masse=50, 2 armes max)" << endl;
        LightWeightWarShip *vc1 = new LightWeightWarShip(10, 50, 2);

        cout << "On équipe VC-1 avec deux phasers (volume=1, masse=1)" << endl;

        Phaser *p1 = new Phaser(1,1);
        Phaser *p2 = new Phaser(1,1);

        vc1->load(p1);
        vc1->load(p2);

        phasers.push_back(p1);
        phasers.push_back(p2);

        cout << "soit un vaisseau de transport VT-2 (volume=100, masse=100, cap_volume=90, cap_masse=300)" << endl;
        TransportShip *vt2 = new TransportShip(100, 100, 90, 300);

        cout << "on charge VT-2 avec 5 conteneurs (volume=1, masse=1)" << endl;
        Container *c;
        for ( int unsigned i = 0 ; i < 5 ; i ++) {
            c = new Container(1,1);
            vt2->load(c);
        }

        cout << "on charge VT-2 avec VC-1" << endl;
        vt2->load(vc1);

        cout << "on déséquipe un des phasers de VC-1 et on le charge dans VT-2 comme du fret" << endl;
        vc1->unload(p1);
        vt2->load(p1);

        cout << "soit MR-63 un vieux modèle de vaisseau de transport lourd capable de se battre (volume=200, masse=150, cap_volume=180, cap_masse=600, 5 armes max)" << endl;
        HybridShip *mr63 = new HybridShip(200, 150, 180, 600, 5);

        cout << "on équipe MR-63 avec deux blasters (volume=2, masse=2, gaz=50%), deux phasers (volume=1, masse=1), le vaisseau VT-2, et 4 conteneurs (volume=10, masse=100)" << endl;
        Blaster *b1 = new Blaster(2,2,50);
        Blaster *b2 = new Blaster(2,2,50);

        mr63->load(b1);
        mr63->load(b2);

        Phaser *p3 = new Phaser(1,1);
        Phaser *p4 = new Phaser(1,1);

        phasers.push_back(p3);
        phasers.push_back(p4);

        mr63->load(p3);
        mr63->load(p4);

        mr63->load(vt2);

        for ( int unsigned i = 0 ; i < 4 ; i ++) {
            c = new Container(10, 100);
            mr63->load(c);
        }

        cout << "on veut savoir quelle est la masse totale de MR-63 (un bon gros 713) et quel est le volume disponible dans MR-63 (il en reste pour 34)" << endl;
        printf("Masse de MR-63: %f.\n", mr63->getMass());
        printf("Volume disponible de MR-63: %f.\n", mr63->getVolumeCapacityRemaining());

//TODO do resolve location final in Equipment
//        cout << "on veut savoir où est chacun des phasers (deux sont dans MR-63, un est dans la soute de VT-2, le dernier est équipé par VC-1 qui est dans la soute de VT-2)" << endl;

        cout << "on veut connaitre le niveau de gaz des blasters équipés par MR-63, puis les recharger" << endl;
        printf("Niveau de gaz de B1 avant rechargement: %f\n", b1->getGazLevel());
        b1->recharge();
        printf("Niveau de gaz de B1 après rechargement: %f\n", b1->getGazLevel());

        printf("Niveau de gaz de B2 avant rechargement: %f\n", b2->getGazLevel());
        b2->recharge();
        printf("Niveau de gaz de B2 après rechargement: %f\n", b2->getGazLevel());
    }

    void resolveLocation(Equipment*) {

    }
    // virtual void TearDown() {}
    HybridShip *hybridShip;
};

