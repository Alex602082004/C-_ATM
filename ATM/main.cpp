#include <iostream>
#include "vector_dinamic.h"
#include "colection.h"
#include "tranzactie.h"
#include "atm.h"
#include "ui.h"
#include "inputs.h"

using namespace std;

int main() {

    Collection c;
    create_collection(c);
    ATM a(c);
    UI ui(a);
    ui.run();


    return 0;
}
