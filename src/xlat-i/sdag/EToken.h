/*****************************************************************************
 * $Source$
 * $Author$
 * $Date$
 * $Revision$
 *****************************************************************************/

#ifndef _EToken_H_
#define _EToken_H_

enum EToken {
   DEFAULT=1

  ,SIDENT=2
  ,SLBRACE=3
  ,SRBRACE=4
  ,SLB=5
  ,SRB=6
  ,SLP=7
  ,SRP=8
  ,SCOLON=9
  ,SSTAR=10
  ,SCHAR=11
  ,SSTRING=12
  ,SNEW_LINE=13
  ,SCLASS=14
  ,SENTRY=15
  ,SSDAGENTRY=16
  ,SOVERLAP=17
  ,SWHEN=18
  ,SIF=19
  ,SWHILE=20
  ,SFOR=21
  ,SFORALL=22
  ,SATOMIC=23
  ,SCOMMA=24
  ,SELSE=25
  ,SSEMICOLON=26
  ,SPARAMLIST=27
  ,SPARAMETER=28
  ,SVARTYPELIST=29
  ,SVARTYPE=30
  ,SFUNCTYPE=31
  ,SSIMPLETYPE=32
  ,SBUILTINTYPE=33
  ,SONEPTRTYPE=34
  ,SPTRTYPE=35
  ,SINT=36
  ,SLONG=37
  ,SSHORT=38
  ,SUNSIGNED=39
  ,SDOUBLE=40
  ,SVOID=41
  ,SFLOAT=42
  ,SCONST=43
  ,SEQUAL=44
  ,SAMPERESIGN=45
  ,SLITERAL=46
  ,SNUMBER=47
  ,SFORWARD=48
  ,SCONNECT=49
  ,SPUBLISHES=50

  ,SMATCHED_CPP_CODE=100
  ,SINT_EXPR=101
  ,SWSPACE=102
  ,SSLIST=103
  ,SELIST=104
  ,SOLIST=105
};

#endif /* _EToken_H_ */
