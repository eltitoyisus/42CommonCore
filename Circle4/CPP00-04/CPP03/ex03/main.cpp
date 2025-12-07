/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 05:35:28 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/14 05:35:28 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	std::cout << "== ClapTrap big test ==" << std::endl;

	std::cout << "\nCreating ClapTraps..." << std::endl;
	ClapTrap player1("Warrior");
	ClapTrap player2("Mage");
	ClapTrap player3;
	player3 = player1;

	std::cout << "\nTesting setAttackDamage..." << std::endl;
	player1.setAttackDamage(5);
	player2.setAttackDamage(3);

	std::cout << "\nInitial attacks:" << std::endl;
	player1.attack(player2.getName());
	player2.takeDamage(player1.getAttackDamage());

	player2.attack(player1.getName());
	player1.takeDamage(player2.getAttackDamage());

	std::cout << "\nRepairing both ClapTraps..." << std::endl;
	player1.beRepaired(4);
	player2.beRepaired(2);

	std::cout << "\nCopy constructed ClapTrap:" << std::endl;
	ClapTrap player4(player2);
	player4.attack("Dummy Target");

	std::cout << "\nStress test: attacking until out of energy..." << std::endl;
	for (int i = 0; i < 15; ++i) {
		player1.attack("Orc");
	}

	std::cout << "\nTrying to repair with 0 energy:" << std::endl;
	player1.beRepaired(10);

	std::cout << "\nDealing lethal damage:" << std::endl;
	player2.takeDamage(20);

	std::cout << "\nTrying to attack while dead:" << std::endl;
	player2.attack("Ghost");

	std::cout << "\nTrying to repair while dead:" << std::endl;
	player2.beRepaired(5);

	std::cout << "\nManual test of 0 HP edge case:" << std::endl;
	player3.takeDamage(10);
	player3.takeDamage(10);

	std::cout << "\nTesting multiple repairs to see HP limit..." << std::endl;
	player3.beRepaired(100);

	std::cout << "\n== SCAVTRAP TESTS ==" << std::endl;

	std::cout << "\nCreating ScavTraps..." << std::endl;
	ScavTrap scav1("Guardian");
	ScavTrap scav2("Protector");

	std::cout << "\nAttacking with ScavTraps..." << std::endl;
	scav1.attack(scav2.getName());
	scav2.takeDamage(20);

	scav2.attack(scav1.getName());
	scav1.takeDamage(20);

	std::cout << "\nRepairing ScavTraps..." << std::endl;
	scav1.beRepaired(15);
	scav2.beRepaired(10);

	std::cout << "\nTesting guardGate mode..." << std::endl;
	scav1.guardGate();
	scav2.guardGate();

	std::cout << "\nStress test ScavTrap attacks until energy depletes..." << std::endl;
	for (int i = 0; i < 55; ++i) {
		scav1.attack("Dummy Target");
	}

	std::cout << "\nTrying to guardGate with no energy:" << std::endl;
	scav1.guardGate();

	std::cout << "\nDealing lethal damage to ScavTrap:" << std::endl;
	scav2.takeDamage(200);

	std::cout << "\nTrying to attack while dead:" << std::endl;
	scav2.attack("Ghost");

	std::cout << "\nTrying to repair while dead:" << std::endl;
	scav2.beRepaired(5);

	/***********************************************************************
	**                     FRAGTRAP TESTS
	***********************************************************************/
	std::cout << "\n== FRAGTRAP TESTS ==" << std::endl;

	std::cout << "\nCreating FragTraps..." << std::endl;
	FragTrap frag1("Bomber");
	FragTrap frag2("Blaster");
	FragTrap frag3;
	frag3 = frag1;

	std::cout << "\nInitial attacks:" << std::endl;
	frag1.attack(frag2.getName());
	frag2.takeDamage(frag1.getAttackDamage());

	frag2.attack(frag1.getName());
	frag1.takeDamage(frag2.getAttackDamage());

	std::cout << "\nRepairing FragTraps..." << std::endl;
	frag1.beRepaired(20);
	frag2.beRepaired(15);

	std::cout << "\nCopy constructed FragTrap:" << std::endl;
	FragTrap frag4(frag2);
	frag4.attack("Training Dummy");

	std::cout << "\nTesting highFivesGuys():" << std::endl;
	frag1.highFivesGuys();
	frag2.highFivesGuys();

	std::cout << "\nStress test FragTrap attacks until energy depletes..." << std::endl;
	for (int i = 0; i < 105; ++i) {
		frag1.attack("Target Dummy");
	}

	std::cout << "\nTrying to high five with no energy:" << std::endl;
	frag1.highFivesGuys();

	std::cout << "\nDealing lethal damage to FragTrap:" << std::endl;
	frag2.takeDamage(500);

	std::cout << "\nTrying to attack while dead:" << std::endl;
	frag2.attack("Ghost");

	std::cout << "\nTrying to repair while dead:" << std::endl;
	frag2.beRepaired(30);

	std::cout << "\nManual test of 0 HP edge case:" << std::endl;
	frag3.takeDamage(50);
	frag3.takeDamage(60);

	std::cout << "\nTesting multiple repairs to see HP limit..." << std::endl;
	frag3.beRepaired(500);

	std::cout << "\n== DIAMONDTRAP TESTS ==" << std::endl;

	std::cout << "\nCreating DiamondTraps..." << std::endl;
	DiamondTrap dia1("DiamondOne");
	DiamondTrap dia2("DiamondTwo");

	std::cout << "\nTesting whoAmI()..." << std::endl;
	dia1.whoAmI();
	dia2.whoAmI();

	std::cout << "\nAttacking with DiamondTraps..." << std::endl;
	dia1.attack(dia2.getName());
	dia2.takeDamage(dia1.getAttackDamage());

	dia2.attack(dia1.getName());
	dia1.takeDamage(dia2.getAttackDamage());

	std::cout << "\nRepairing DiamondTraps..." << std::endl;
	dia1.beRepaired(30);
	dia2.beRepaired(20);

	std::cout << "\nStress test DiamondTrap attacks until energy depletes..." << std::endl;
	for (int i = 0; i < 55; ++i) {
		dia1.attack("Dummy Target");
	}

	std::cout << "\nTrying whoAmI with no energy:" << std::endl;
	dia1.whoAmI();

	std::cout << "\nDealing lethal damage to DiamondTrap:" << std::endl;
	dia2.takeDamage(500);

	std::cout << "\nTrying to attack while dead:" << std::endl;
	dia2.attack("Ghost");

	std::cout << "\nTrying to repair while dead:" << std::endl;
	dia2.beRepaired(30);

	std::cout << "\n== End of DIAMONDTRAP test ==" << std::endl;


	std::cout << "\n== End of test ==" << std::endl;

	return 0;
}
