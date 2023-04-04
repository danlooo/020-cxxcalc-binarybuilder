
# Note that this script can accept some limited command-line arguments, run
# `julia build_tarballs.jl --help` to see a usage message.
using BinaryBuilder, Pkg

name = "cxxcalc"
version = v"0.1.0"

# Collection of sources required to complete build
sources = [
    GitSource("https://github.com/danlooo/CxxCalc.jl.git", "7297bd1cc66561e7c93fb34364621253924c5b23")
]

# Bash recipe for building across all platforms
script = raw"""
cd $WORKSPACE/srcdir/CxxCalc.jl/cxxcalc
ls
exit
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
]

# Build the tarballs, and possibly a `build.jl` as well.
build_tarballs(ARGS, name, version, sources, script, platforms, products, dependencies; preferred_gcc_version=v"9.4.0")