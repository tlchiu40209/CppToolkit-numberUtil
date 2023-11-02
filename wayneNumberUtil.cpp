/*
 * wayneNumberUtil.cpp
 *
 *  Created on: 2023年10月22日
 *      Author: weich
 */

#include "wayneNumberUtil.hpp"

namespace wayne {
	namespace numberUtil {
		template<typename integerType> std::vector<char> numberToBytes(integerType const& number, bool forceBigEndian)
		{
			std::vector<char> toReturn;
			for (int i = 0; i < sizeof(number); i++) {
				toReturn.push_back((number >> (i * 8)));
			}
			if (isBigEndian() || forceBigEndian) {
				std::reverse(toReturn.begin(), toReturn.end());
			}
			return toReturn;
		}

		template<typename integerType> char* numberToBytesStatic(integerType const& number, bool forceBigEndian)
		{
			std::vector<char> toHandle = numberToBytes(number, forceBigEndian);
			char* toReturn = new char[toHandle.size()];
			std::copy(toHandle.begin(), toHandle.end(), toReturn);
			return toReturn;
		}

		template<typename integerType> integerType bytesToNumber(std::vector<char> rawBytes, integerType const& referenceType, bool rawIsBigEndian)
		{
			if (rawBytes.size() != sizeof(referenceType)) {
				wayne::IO::logLn("Provided length of data bytes does not match with the provided reference type", true);
				return 0;
			}
			else
			{
				if (isBigEndian && !isBigEndian()) //If the given data is big endian, but the processor is not.
				{
					std::reverse(rawBytes.begin(), rawBytes.end());
				}
				integerType toReturn;
				unsigned char* buffer = new unsigned char[rawBytes.size()];
				std::copy(rawBytes.begin(), rawBytes.end(), buffer);
				toReturn = *((integerType*)buffer);
				delete[] buffer;
				return toReturn;
		    }
		}

		template<typename integerType> integerType bytesStaticToNumber(char* rawBytes, numberDataLength dataLength, integerType const& referenceType, bool rawIsBigEndian)
		{
			std::vector<char> toRecur(dataLength);
			std::copy(rawBytes, rawBytes + dataLength, toRecur);
			return bytesToNumber(toRecur, referenceType, isBigEndian);
		}

		bool isBigEndian()
		{
			short int testWord = 0x0001;
			char* testByte = (char*) &testWord;
			return (testByte[0] == '\x00' ? true : false);
		}
	} /* namespace numberUtil */
} /* namespace wayne */
