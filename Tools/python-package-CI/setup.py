#!/usr/bin/env python
# coding: utf-8

from setuptools import setup, find_packages

setup(  name = 'learn',
        version = '0.1',
        url = 'https://github.com/Dawnstar8411/python-package-CI.git',
        license = 'MIT',
        author = 'WangChen',
        author_email = 'dawnstar8411@163.com',
        description = 'Learn python Package',
        keywords = 'packages, CI',
        packages = find_packages(exclude = ['tests']), 
        long_description = open('README.md').read(),
        zip_safe = False,
        install_requires = ['nose>=1.0', "numpy","scikit-learn"],
        test_suite = 'nose.collector',
	)
