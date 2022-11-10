# Mini Search Engine

## Introduction

Search engines act as filters for the wealth of information available on the internet. They allow users to quickly and easily find information that is of genuine interest or value, without the need to wade through numerous irrelevant web pages. The search process is important in computer science as computer systems often stores large amounts of data where individual records must be retrieved according efficiently.

## Technical Description

This project is fully programmed using C++ and compiled using g++ with a C++ version of 17.

### Dataset used

The data for my sample webpages used is from a wikipedia summary dataset which I have gotten from [shag527](https://github.com/shag527/Mini-Search-Engine)'s repository. It contains all titles and summaries of English Wikipedia articles, extracted in September of 2017. For the sample webpages in this repository, I have processed and trimmed down the data into 201 records.

## User Guide

to compile code:
`g++ -std=c++17 *.cpp -o search-engine`

to run code:
`./search-engine.exe <params> <filepath>`

params:

1. `--help`: show help menu
2. `--dir`: provide dir path instead of file path

example: `./search-engine.exe --dir sample_webpages`

## References

- [The importance of search engines](https://www.inetasia.com/resources/articles-the-importance-of-search-engines.html)
- [shag527's repository](https://github.com/shag527/Mini-Search-Engine)
