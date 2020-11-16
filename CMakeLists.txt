cmake_minimum_required(VERSION 3.17)
project(HuffmanCoding C)

set(CMAKE_C_STANDARD 99)

add_executable(HuffmanCoding main.c HuffmanEncoding/InputFile.c HuffmanEncoding/InputFile.h HuffmanEncoding/HuffmanDictionary.c HuffmanEncoding/HuffmanDictionary.h DataTypes/DataTypes.c DataTypes/DataTypes.h HuffmanEncoding/EncodingFile.c HuffmanEncoding/EncodingFile.h HuffmanEncoding/OutputFile.c HuffmanEncoding/OutputFile.h OptimisedHuffmanEncoding/CreateHuffmanTree.c OptimisedHuffmanEncoding/CreateHuffmanTree.h OptimisedHuffmanEncoding/Dictionary.c OptimisedHuffmanEncoding/Dictionary.h OptimisedHuffmanEncoding/EncodingFileOp.c OptimisedHuffmanEncoding/EncodingFileOp.h)