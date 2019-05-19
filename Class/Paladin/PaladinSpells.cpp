#include "PaladinSpells.h"

#include "Buff.h"
#include "Consecration.h"
#include "Judgement.h"
#include "MainhandAttackPaladin.h"
#include "Paladin.h"
#include "PaladinSeal.h"
#include "SanctityAura.h"
#include "SealOfCommand.h"
#include "SealOfTheCrusader.h"

PaladinSpells::PaladinSpells(Paladin* paladin) :
    CharacterSpells(paladin),
    paladin(paladin)
{
    this->consecration = new Consecration(paladin, new_cooldown_control("Consecration", 8.0), 5, 565, 384);
    this->judgement = new Judgement(paladin, new_cooldown_control("Judgement", 10.0));
    this->mh_attack = new MainhandAttackPaladin(paladin);
    this->sanctity_aura = new SanctityAura(paladin);
    this->seal_of_command = new SealOfCommand(paladin);
    this->seal_of_the_crusader = new SealOfTheCrusader(paladin);

    add_spell_group({
                        new Consecration(paladin, new_cooldown_control("Consecration", 8.0), 1, 135, 64),
                        new Consecration(paladin, new_cooldown_control("Consecration", 8.0), 2, 235, 120),
                        new Consecration(paladin, new_cooldown_control("Consecration", 8.0), 3, 320, 192),
                        new Consecration(paladin, new_cooldown_control("Consecration", 8.0), 4, 435, 280),
                        consecration,
                    });
    add_spell_group({judgement});
    add_spell_group({mh_attack});
    add_spell_group({sanctity_aura});
    add_spell_group({seal_of_command});
    add_spell_group({seal_of_the_crusader});
}

Judgement* PaladinSpells::get_judgement() const {
    return this->judgement;
}

PaladinSeal* PaladinSpells::get_seal_of_the_crusader() const {
    return this->seal_of_the_crusader;
}

PaladinSeal* PaladinSpells::get_seal_of_command() const {
    return this->seal_of_command;
}

Consecration* PaladinSpells::get_consecration() const {
    return this->consecration;
}

SanctityAura* PaladinSpells::get_sanctity_aura() const {
    return this->sanctity_aura;
}

void PaladinSpells::apply_seal(PaladinSeal* new_seal) {
    if (current_seal != nullptr && current_seal->get_buff()->get_instance_id() != new_seal->get_buff()->get_instance_id())
        current_seal->get_buff()->cancel_buff();

    current_seal = new_seal;
    current_seal->get_buff()->apply_buff();
}

PaladinSeal* PaladinSpells::get_seal() const {
    return this->current_seal;
}