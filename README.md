# This repository contains tests for libosmp
## This is a proof of concept on test automation

Since this is just a proof of concept it merely has some small functional tests.
An exhaustive testsuite should include unit testing and possibly branch tests.
Since these are however explicit with regard to the actual implementation, they
cannot be generalised. A functional test can be generalized. You'll find examples
of how to possibly do this in this repository. There are some constraints to the
repository used in conjunction with this testsuite (the osmp library repository).
An example implementation can be found at https://git.fh-muenster.de/dk426722/libosmp.
I make no claims that the code found here or in the osmp library are correct, complete
or in anyway good.

### Constraints

1. You need to copy the file '.gitlab-ci.yml' from this repository into the top level
   directory of the library under test (LUT).
2. The LUT shall have a Makefile in its top level directory,
   which can be invoked with just 'make'. It shall produce a 'build' directory at the 
   top level, where 'osmprun' and 'libosmp.a' are being build.
3. The LUT repository needs access to the dockerimage which is defined by the
   'Dockerfile'. (See gitlab documentation on how to add docker images to a repository)
