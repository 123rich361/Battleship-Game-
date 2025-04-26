#include <iostream>
#include <cassert>
#include "AttackResult.h"

using namespace std;

void testAttackResultCreation() {
    
    cout << "Testing AttackResult creation..." << endl;

    AttackResult result1 = {true, false, 'C'};
    assert(result1.hit == true);
    assert(result1.sunk == false);
    assert(result1.shipSymbol == 'C');

    AttackResult result2 = {false, true, 'B'};
    assert(result2.hit == false);
    assert(result2.sunk == true);
    assert(result2.shipSymbol == 'B');

    AttackResult result3 = {false, false, '\0'};
    assert(result3.hit == false);
    assert(result3.sunk == false);
    assert(result3.shipSymbol == '\0');

    cout << "AttackResult creation test passed." << endl;
}