
# Note that this script can accept some limited command-line arguments, run
# `julia build_tarballs.jl --help` to see a usage message.
using BinaryBuilder, Pkg

name = "cxxcalc"
version = v"0.1.0"

# Collection of sources required to complete build
sources = [
    GitSource("https://github.com/danlooo/020-cxxcalc-binarybuilder.git", "b61706d9fd9ee2e5fc68a875b9cf423189a46cef")
]

# Bash recipe for building across all platforms
script = raw"""
cd $WORKSPACE/srcdir/cxxcalc
if [[ "${target}" == x86_64-linux-musl ]]; then
    # Remove libexpat to avoid it being picked up by mistake
    rm /usr/lib/libexpat.so*
fi

export JULIA_LOAD_PATH="@:@v#.#:@stdlib:`pwd`"
export LD_LIBRARY_PATH="`pwd`${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"

make -j${nproc} CCOMP="${CC}" CPPCOMP="${CXX}"
cp *.so "${bindir}/."
"""

# These are the platforms we will build for by default, unless further
# platforms are passed in on the command line
platforms = expand_cxxstring_abis([
    # Platform("x86_64", "windows"),
    # Platform("x86_64", "macos"),
    Platform("x86_64", "linux")
])


# The products that we will ensure are always built
products = [
    LibraryProduct("jlCxxCalc.so", :cxxcalc)
]

# Dependencies that must be installed before this package can be built
dependencies = [
    Dependency("libcxxwrap_julia_jll")
]

# Build the tarballs, and possibly a `build.jl` as well.
build_tarballs(ARGS, name, version, sources, script, platforms, products, dependencies; preferred_gcc_version=v"9.4.0")