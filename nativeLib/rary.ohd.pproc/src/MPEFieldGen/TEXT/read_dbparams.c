/*******************************************************************************
* FILENAME:            read_dbparams.c
*
* Purpose:
* This function loads static data from RWParams and RWBiasStat tables.
* parameters are plugged into mpe_params_struct.
*
* calling function: main_mpe_fieldgen
* functions called: readRWParams, readRWBiasStat
*
* ORIGINAL AUTHOR:       Guoxian Zhou
* CREATION DATE:         March, 2005
* ORGANIZATION:          HSEB / OHD
* MACHINE:               HP-UX / Dell-Redhat Linux
* MODIFICATION HISTORY:
*   DATE         PROGRAMMER        DESCRIPTION/REASON
*   March 2005   Guoxian Zhou      Finish first version 
*
********************************************************************************
*/

#include "mpe_fieldgen.h"

void MPEFieldGen_readDBParams(mpe_params_struct * pMPEParams)
{
    float memory_span = 0.0;
    int  i;
    long int  status = 0 ;

    /****************** read from database tables ************************/

    /**
     *    read from RWParams table
     **/
    MPEFieldGen_readRWParams(pMPEParams->ptrRWParams, &status);

    if(status != 0)
    {
        sprintf ( message , "Database error:%ld,"
            " attempting select from RWParams table."
            "\n\tProgram exit.", status) ;
        shutDownMPE( message, logFile );
    }

    /**
     *    read from RWBiasStat table
     **/
    MPEFieldGen_readRWBiasStat(pMPEParams->ptrRWBiasStat, 
                   pMPEParams->fxa_local_site,
                   &status);

    if(status != 0)
    {
        sprintf ( message , "Database error:%ld, "
            "attempting select from RWBiasStatParm table."
            "\n\tProgram exit.", status) ;
        shutDownMPE( message, logFile );
    }

    /* Initialize the memory_spans array member of the MPE Params
       structure for future reference by other portions of MPE
       fieldgen. */
    if ( pMPEParams->ptrRWBiasStat->num_span > NUM_MEMORY_SPANS )
    {
        sprintf ( message , "NUM_MEMORY_SPANS is not large enough "
              "to contain all of the memory spans in\n"
              "the RWBiasStat table.\n"
              "NUM_MEMORY_SPANS = %d  Require number "
              "of spans = %ld.\n", NUM_MEMORY_SPANS,
              pMPEParams->ptrRWBiasStat->num_span );
        shutDownMPE( message, logFile );
    }

    for ( i = 0; i < pMPEParams->ptrRWBiasStat->num_span; ++i )
    {
        switch ( i )
        {
           case 0:
              memory_span = pMPEParams->ptrRWBiasStat->mem_span1;
              break;

           case 1:
              memory_span = pMPEParams->ptrRWBiasStat->mem_span2;
              break;

           case 2:
              memory_span = pMPEParams->ptrRWBiasStat->mem_span3;
              break;

           case 3:
              memory_span = pMPEParams->ptrRWBiasStat->mem_span4;
              break;

           case 4:
              memory_span = pMPEParams->ptrRWBiasStat->mem_span5;
              break;

           case 5:
              memory_span = pMPEParams->ptrRWBiasStat->mem_span6;
              break;

           case 6:
              memory_span = pMPEParams->ptrRWBiasStat->mem_span7;
              break;

           case 7:
              memory_span = pMPEParams->ptrRWBiasStat->mem_span8;
              break;

           case 8:
              memory_span = pMPEParams->ptrRWBiasStat->mem_span9;
              break;

           case 9:
              memory_span = pMPEParams->ptrRWBiasStat->mem_span10;
              break;

           default:

              sprintf ( message, "Reached default block in memory "
                                 "span switch statement ... error." );
              shutDownMPE ( message, logFile ); 
              break;
        }

        pMPEParams->memory_spans [ i ] = memory_span; 
    }

/*  ==============  Statements containing RCS keywords:  */
{static char rcs_id1[] = "$Source: /fs/hseb/ob83/ohd/pproc_lib/src/MPEFieldGen/RCS/read_dbparams.c,v $";
 static char rcs_id2[] = "$Id: read_dbparams.c,v 1.1 2007/10/15 12:19:12 dsa Exp lawrence $";}
/*  ===================================================  */

}
