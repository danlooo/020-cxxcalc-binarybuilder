using BinaryBuilder
state = BinaryBuilder.run_wizard()

libcxxwrap_julia_jll
libjulia_jll

cd $WORKSPACE/srcdir
export JlCxx_DIR=/workspace/$target/destdir/lib/cmake/JlCxx/
cd 020-cxxcalc-binarybuilder/src
cmake -DCMAKE_INSTALL_PREFIX=$prefix -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TARGET_TOOLCHAIN} -DCMAKE_BUILD_TYPE=Release .
make
mkdir -p ${bindir}
cp lib/* $bindir

# pretend to create both lib and bin
mkdir bin
echo echo hello > bin/cxxcalc
chmod +x bin/cxxcalc 


┌ Warning: /tmp/jl_kVA7YDkZ2d/DcxHcmlz/i686-linux-gnu-libgfortran5-cxx11/destdir/bin contains std::string values!  This causes incompatibilities across the GCC 4/5 version boundary.  To remedy this, you must build a tarball for both GCC 4 and GCC 5.  To do this, immediately after your `platforms` definition in your `build_tarballs.jl` file, add the line:
│ 
│     platforms = expand_cxxstring_abis(platforms)
