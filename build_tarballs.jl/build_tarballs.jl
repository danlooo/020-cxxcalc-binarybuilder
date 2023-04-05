# Note that this script can accept some limited command-line arguments, run
# `julia build_tarballs.jl --help` to see a usage message.
using BinaryBuilder, Pkg

name = "cxxcalc"
version = v"0.1.0"

# Collection of sources required to complete build
sources = [
    GitSource("https://github.com/danlooo/020-cxxcalc-binarybuilder.git", "b4021e03c83249b60b1dfffeb98ff752e5f56cad")
]

# Bash recipe for building across all platforms
script = raw"""
cd $WORKSPACE/srcdir
export JlCxx_DIR=/workspace/$target/destdir/lib/cmake/JlCxx/
cd 020-cxxcalc-binarybuilder/src
cmake -DCMAKE_INSTALL_PREFIX=$prefix -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TARGET_TOOLCHAIN} -DCMAKE_BUILD_TYPE=Release .
make
mkdir -p ${bindir}
cp lib/* $bindir
"""

# These are the platforms we will build for by default, unless further
# platforms are passed in on the command line
platforms = [
    Platform("x86_64", "linux"; libc="glibc"),
    Platform("aarch64", "linux"; libc="glibc")
]


# The products that we will ensure are always built
products = [
    LibraryProduct("libCxxCalc", :cxxcalc)
]

# Dependencies that must be installed before this package can be built
dependencies = [
    Dependency(PackageSpec(name="libjulia_jll", uuid="5ad3ddd2-0711-543a-b040-befd59781bbf"))
    Dependency(PackageSpec(name="libcxxwrap_julia_jll", uuid="3eaa8342-bff7-56a5-9981-c04077f7cee7"))
]

# Build the tarballs, and possibly a `build.jl` as well.
build_tarballs(ARGS, name, version, sources, script, platforms, products, dependencies; julia_compat="1.6", preferred_gcc_version=v"9.1.0")
