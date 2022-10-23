/* Country.c file
 *
 * function defs for country.h in public
 * 
 * @QWERTYghri
 */


#include <stdlib.h>
#include "../public/country.h"

Country* cntryInit ()
{
        Country* link = calloc ( 1, sizeof ( Country ) );
