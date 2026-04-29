# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Vitaly/StudyDrive/SecondYear/AdvancedSystemProgramming/Project_ASP/cmake-build-debug/_deps/googletest-src"
  "C:/Vitaly/StudyDrive/SecondYear/AdvancedSystemProgramming/Project_ASP/cmake-build-debug/_deps/googletest-build"
  "C:/Vitaly/StudyDrive/SecondYear/AdvancedSystemProgramming/Project_ASP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "C:/Vitaly/StudyDrive/SecondYear/AdvancedSystemProgramming/Project_ASP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "C:/Vitaly/StudyDrive/SecondYear/AdvancedSystemProgramming/Project_ASP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "C:/Vitaly/StudyDrive/SecondYear/AdvancedSystemProgramming/Project_ASP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "C:/Vitaly/StudyDrive/SecondYear/AdvancedSystemProgramming/Project_ASP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Vitaly/StudyDrive/SecondYear/AdvancedSystemProgramming/Project_ASP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Vitaly/StudyDrive/SecondYear/AdvancedSystemProgramming/Project_ASP/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
