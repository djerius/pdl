# Makefile.PL for a package defined by PP code.

use PDL::Core::Dev;            # Pick up development utilities
use ExtUtils::MakeMaker;

$package = ["indxxx.pd",qw(IndOps PDL::IndOps)];
%hash = pdlpp_stdargs($package);
$hash{OBJECT} .= ''; #' additional_Ccode$(OBJ_EXT) ';
$hash{clean}->{FILES} .= ''; #' todelete_Ccode$(OBJ_EXT) ';
$hash{'VERSION_FROM'} = 'indxxx.pd';
WriteMakefile(%hash);

sub MY::postamble { pdlpp_postamble($package); }

