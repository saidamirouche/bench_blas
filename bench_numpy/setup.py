import setuptools

setuptools.setup(
    name="bench_numpy",
    version="0.0.1",
    author="Example Author",
    author_email="author@example.com",
    scripts=['bin/test.py'],
    description="A small example package",
    long_description_content_type="text/markdown",
    url="https://github.com/samirouche/bench_blas",
    packages=setuptools.find_packages(),
    classifiers=(
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ),
)
