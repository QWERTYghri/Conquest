/* Country.c file
 *
 * function defs for country.h in public
 * 
 * @QWERTYghri
 */


#include <stdlib.h>
#include "../public/country.h"

Country* cntryInit ( void )
{
        return calloc ( 1, sizeof ( Country ) );
}
