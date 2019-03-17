#ifndef TESTAUTOSHOOT_H
#define TESTAUTOSHOOT_H

#include "TestSpellHunter.h"

class AutoShoot;

class TestAutoShoot: public TestSpellHunter {
public:
    TestAutoShoot(EquipmentDb *equipment_db);

    void test_all();

private:
    AutoShoot* auto_shoot();

    void test_name_correct() override;
    void test_spell_cooldown() override;
    void test_incurs_global_cooldown() override;
    void test_obeys_global_cooldown() override;
    void test_resource_cost() override;
    void test_is_ready_conditions() override;

    void test_changing_weapons_changes_cooldown();
    void test_hit_dmg();
    void test_crit_dmg();
    void test_mid_swing_haste_increase_updates_attack_speed();
    void test_mid_swing_haste_decrease_updates_attack_speed();

    void when_auto_shoot_is_performed();
    void when_changing_to_2_speed();
    void when_increasing_attack_speed(const unsigned change);
    void when_decreasing_attack_speed(const unsigned change);

    void then_next_expected_use_is(const double next_expected_use);
};

#endif // TESTAUTOSHOOT_H