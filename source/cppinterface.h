#ifndef CPPINTERFACE_H
#define CPPINTERFACE_H

#include "xlw/MyContainers.h"
#include <xlw/CellMatrix.h>
#include <xlw/DoubleOrNothing.h>
#include <xlw/ArgList.h>
#include "volmodel.h"
#include "pricer.h"
#include "fxpricer.h"
#include "math_utils.h"
#include "timeseries.h"
#include "sqlserveraccess.h"
#include "barriersmile.h"

using namespace xlw;

//<xlw:libraryname=MyTestLibrary

MyArray CLFitDelta5VolParams( const double dtoday,
					const double dexp,
					const double fwd,
					const MyArray &strikeList,
					const MyArray &volList);

double CLSmileVolbyStrike(const double dtoday,
					const double dexp,
					const double fwd,
					const double atm, 
					const double v90, 
					const double v75, 
					const double v25, 
					const double v10,
					const double K);

double CLSmileVolbyDelta(const double dtoday,
					const double dexp,
					const double fwd,
					const double atm, 
					const double v90, 
					const double v75, 
					const double v25, 
					const double v10,
					const double delta);

double CLSmileEuroOptPricer(const double dtoday,
					const double dexp,
					const double fwd,
					const double strike,
					const double atm, 
					const double v90, 
					const double v75, 
					const double v25, 
					const double v10,
					const double doptexp,
					const double ir,
					const std::string otype,
					const std::string outflag,
					const double alpha,
					const double beta);

double CLEuroOptStripPricer(const double dtoday,
					const double dstart,
					const double dend,
					const double fwd,
					const double strike,
					const double atm, 
					const double v90, 
					const double v75, 
					const double v25, 
					const double v10,
					const double doptexp,
					const double ir,
					const std::string otype,
					const std::string outflag,
					const MyArray &hols,
					const double alpha,
					const double beta);

double CLSmileBinOptPricer(const double dtoday,
					const double dexp,
					const double fwd,
					const double strike,
					const double atm, 
					const double v90, 
					const double v75, 
					const double v25, 
					const double v10,
					const double doptexp,
					const double ir,
					const std::string otype,
					const std::string outflag,
					const double alpha,
					const double beta);

double CLDigitalStripPricer(const double dtoday,
					const double dstart,
					const double dend,
					const double fwd,
					const double strike,
					const double atm, 
					const double v90, 
					const double v75, 
					const double v25, 
					const double v10,
					const double doptexp,
					const double ir,
					const std::string otype,
					const std::string outflag,
					const MyArray &hols,
					const double alpha,
					const double beta);

double CLSprdOptPricer(const double dtoday,
					const double dexp,
					const double fwd,
					const double strike,
					const double atm, 
					const double ir,
					const std::string otype,
					const std::string outflag);

double CLBlackImpliedVol(const double dtoday, 
					const double dexp, 
					const double fwd, 
					const double strike, 
					const double ir,
					const std::string otype, 
					const double optPrice);

double CLBachelierImpliedVol(const double dtoday, 
					const double dexp, 
					const double fwd, 
					const double strike, 
					const double ir,
					const std::string otype, 
					const double prem);

double CLBlackDelta(const double dtoday, 
					const double dexp, 
					const double fwd,
					const double strike,
					const double vol,
					const double ir, 
					const std::string otype);

double CLBarrierOptFlatVolPricer(const double dtoday,
					const double dexp,
					const double fwd,
					const double strike,
					const double barrier,
					const std::string btype,
					const double atm, 
					const double doptexp,
					const double ir,			
					const std::string otype,
					const std::string mtype,
					const std::string outflag,
					const double alpha,
					const double beta);

double CLBarrierOptSmilePricer(const double dtoday,
					const double dexp,
					const double fwd,
					const double strike,
					const double barrier,
					const std::string btype,
					const double atm, 
					const double v90, 
					const double v75, 
					const double v25, 
					const double v10,
					const double doptexp,
					const double ir,			
					const std::string otype,
					const std::string mtype,
					const std::string outflag,
					const double alpha,
					const double beta);

double CLBarrierStripPricer(const double dtoday,
					const double dstart,
					const double dend,
					const double fwd,
					const double strike,
					const double barrier,
					const std::string btype,
					const double atm, 
					const double doptexp,
					const double ir,			
					const std::string otype,
					const std::string mtype,
					const std::string outflag,
					const MyArray &hols,
					const double alpha,
					const double beta);

int CLCalibHistBreakevenVol(std::string hostname, 
							std::string dbname, 
							std::string tablename,
							int sprdnum, 
							int expbackdays, 
							int freq,
							const MyArray &contDates,
							std::string out_table);
MyArray CLFXEuroOptPricer(const double dtoday,
					const double dexp,
					const double fwd,
					const double strike,
					const double atm, 
					const double doptexp,
					const double ir,
					const std::string otype,
					const MyArray &fxFwdTenors,
					const MyArray &fxFwds,
					const MyArray &fxVolTenors,
					const MyArray &fxVols,
					const double corr,
					const std::string outflag,
					const double alpha,
					const double beta);
MyArray CLFXBinOptPricer(const double dtoday,
					const double dexp,
					const double fwd,
					const double strike,
					const double atm, 
					const double doptexp,
					const double ir,
					const std::string otype,
					const MyArray &fxFwdTenors,
					const MyArray &fxFwds,
					const MyArray &fxVolTenors,
					const MyArray &fxVols,
					const double corr,
					const std::string outflag,
					const double alpha,
					const double beta);							
#endif
