/*
 * wayneNumberUtil.cpp
 *
 *  Created on: 2023年10月22日
 *      Author: weich
 */

#include "wayneNumberUtil.hpp"

namespace wayne {
	namespace numberUtil {

		std::vector<char> intToHexBytes(int number, bool isFixedLength, int fixedLength, char padByte)
		{
			bool isNegative = (number > 0) ? true : false;
			if (isNegative)
			{
				number = -number;
			}

			int expectedBytes = 1;
			int handlingNumber = number;
			bool countingBytes = true;
			while (countingBytes)
			{
				if (handlingNumber / 256 > 1)
				{
					handlingNumber = handlingNumber / 256;
					expectedBytes++;
				}
				else
				{
					countingBytes = false;
				}
			}

			std::vector<char> hexBytes;
			if (isNegative)
			{
				if (isFixedLength)
				{
					if (fixedLength < 1)
					{
						wayne::IO::logLn("Request cannot be completed if fixed length is defined, without a length given.", true);
						return hexBytes;
					}
					number = getTwosComplimentUnsignedInt(number, fixedLength);
				}
				else
				{
					int maxSignedNumber = 1;
					for (int i = 0; i < expectedBytes; i++)
					{
						maxSignedNumber *= 256;
					}
					if (number >= (maxSignedNumber/2))
					{
						number = getTwosComplimentUnsignedInt(number, expectedBytes + 1);
					}
					else
					{
						number = getTwosComplimentUnsignedInt(number, expectedBytes);
					}
				}
			}

			if (isFixedLength && expectedBytes > fixedLength)
			{
				if (fixedLength < 1)
				{
					wayne::IO::logLn("Request cannot be completed if fixed length is defined, without a length given.", true);
					return hexBytes;
				}
				wayne::IO::logLn("Given number cannot be fitted into given fixed length of bytes", true);
				number = 1;
				for (int i = 0; i < fixedLength; i++)
				{
					number = number * 256;
				}
				number--;
			}

			for (int i = 0; i < expectedBytes; i++)
			{
				hexBytes.push_back((number >> i * 8));
			}

			if (isFixedLength && !isNegative)
			{
				if (fixedLength < 1)
				{
					wayne::IO::logLn("Request cannot be completed if fixed length is defined, without a length given.", true);
					return hexBytes;
				}
				if (hexBytes.size() < (size_t)fixedLength)
				{
					for (int i = 0; i < (fixedLength - (int)hexBytes.size()); i++)
					{
						hexBytes.push_back(padByte);
					}
				}
			}
			std::reverse(hexBytes.begin(), hexBytes.end());
			return hexBytes;
		}

		std::vector<char> longToHexBytes(long number, bool isFixedLength, int fixedLength, char padByte)
		{
			bool isNegative = (number > 0) ? true : false;
			if (isNegative)
			{
				number = -number;
			}

			int expectedBytes = 1;
			long handlingNumber = number;
			bool countingBytes = true;
			while (countingBytes)
			{
				if (handlingNumber / 256 > 1)
				{
					handlingNumber = handlingNumber / 256;
					expectedBytes++;
				}
				else
				{
					countingBytes = false;
				}
			}

			std::vector<char> hexBytes;
			if (isNegative)
			{
				if (isFixedLength)
				{
					if (fixedLength < 1)
					{
						wayne::IO::logLn("Request cannot be completed if fixed length is defined, without a length given.", true);
						return hexBytes;
					}
					number = getTwosComplimentUnsignedLong(number, fixedLength);
				}
				else
				{
					long maxSignedNumber = 1;
					for (int i = 0; i < expectedBytes; i++)
					{
						maxSignedNumber *= 256;
					}
					if (number >= (maxSignedNumber/2))
					{
						number = getTwosComplimentUnsignedInt(number, expectedBytes + 1);
					}
					else
					{
						number = getTwosComplimentUnsignedInt(number, expectedBytes);
					}
				}
			}

			if (isFixedLength && expectedBytes > fixedLength)
			{
				if (fixedLength < 1)
				{
					wayne::IO::logLn("Request cannot be completed if fixed length is defined, without a length given.", true);
					return hexBytes;
				}
				wayne::IO::logLn("Given number cannot be fitted into given fixed length of bytes", true);
				number = 1;
				for (int i = 0; i < fixedLength; i++)
				{
					number = number * 256;
				}
				number--;
			}

			for (int i = 0; i < expectedBytes; i++)
			{
				hexBytes.push_back((number >> i * 8));
			}

			if (isFixedLength && !isNegative)
			{
				if (fixedLength < 1)
				{
					wayne::IO::logLn("Request cannot be completed if fixed length is defined, without a length given.", true);
					return hexBytes;
				}
				if (hexBytes.size() < (size_t)fixedLength)
				{
					for (int i = 0; i < (fixedLength - (int)hexBytes.size()); i++)
					{
						hexBytes.push_back(padByte);
					}
				}
			}
			std::reverse(hexBytes.begin(), hexBytes.end());
			return hexBytes;
		}

		std::vector<char> unsignedIntToHexBytes(unsigned int number, bool isFixedLength, int fixedLength, char padByte)
		{
			int expectedBytes = 1;
			unsigned int handlingNumber = number;
			bool countingBytes = true;
			while (countingBytes)
			{
				if (handlingNumber / 256 > 1)
				{
					handlingNumber = handlingNumber / 256;
					expectedBytes++;
				}
				else
				{
					countingBytes = false;
				}
			}

			std::vector<char> hexBytes;
			if (isFixedLength && expectedBytes > fixedLength)
			{
				if (fixedLength < 1)
				{
					wayne::IO::logLn("Request cannot be completed if fixed length is defined, without a length given.", true);
					return hexBytes;
				}
				wayne::IO::logLn("Given number cannot be fitted into given fixed length of bytes", true);
				number = 1;
				for (int i = 0; i < fixedLength; i++)
				{
					number = number * 256;
				}
				number--;
			}

			for (int i = 0; i < expectedBytes; i++)
			{
				hexBytes.push_back((number >> i * 8));
			}

			if (isFixedLength)
			{
				if (fixedLength < 1)
				{
					wayne::IO::logLn("Request cannot be completed if fixed length is defined, without a length given.", true);
					return hexBytes;
				}
				if (hexBytes.size() < (size_t)fixedLength)
				{
					for (int i = 0; i < (fixedLength - (int)hexBytes.size()); i++)
					{
						hexBytes.push_back(padByte);
					}
				}
			}
			std::reverse(hexBytes.begin(), hexBytes.end());
			return hexBytes;
		}

		std::vector<char> unsignedIntToHexBytes(unsigned long number, bool isFixedLength, int fixedLength, char padByte)
		{
			int expectedBytes = 1;
			unsigned long handlingNumber = number;
			bool countingBytes = true;
			while (countingBytes)
			{
				if (handlingNumber / 256 > 1)
				{
					handlingNumber = handlingNumber / 256;
					expectedBytes++;
				}
				else
				{
					countingBytes = false;
				}
			}

			std::vector<char> hexBytes;
			if (isFixedLength && expectedBytes > fixedLength)
			{
				if (fixedLength < 1)
				{
					wayne::IO::logLn("Request cannot be completed if fixed length is defined, without a length given.", true);
					return hexBytes;
				}
				wayne::IO::logLn("Given number cannot be fitted into given fixed length of bytes", true);
				number = 1;
				for (int i = 0; i < fixedLength; i++)
				{
					number = number * 256;
				}
				number--;
			}

			for (int i = 0; i < expectedBytes; i++)
			{
				hexBytes.push_back((number >> i * 8));
			}

			if (isFixedLength)
			{
				if (fixedLength < 1)
				{
					wayne::IO::logLn("Request cannot be completed if fixed length is defined, without a length given.", true);
					return hexBytes;
				}
				if (hexBytes.size() < (size_t)fixedLength)
				{
					for (int i = 0; i < (fixedLength - (int)hexBytes.size()); i++)
					{
						hexBytes.push_back(padByte);
					}
				}
			}
			std::reverse(hexBytes.begin(), hexBytes.end());
			return hexBytes;
		}

		char* intToHexBytesStatic(int number, bool isFixedLength, int fixedLength, char padByte)
		{
			if (!isFixedLength)
			{
				wayne::IO::logLn("Warning! It will be no way for you to know the size of the array if you did not assign the size of the byte array explicitly.", true);
			}
			if (fixedLength < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return nullptr;
			}
			std::vector<char> toHandle = intToHexBytes(number, isFixedLength, fixedLength, padByte);
			if (toHandle.size() < (size_t)1)
			{
				wayne::IO::logLn("Your request cannot be completed.");
				return nullptr;
			}
			char* toReturn = new char[toHandle.size()];
			for (size_t i = 0; i < toHandle.size(); i++)
			{
				toReturn[i] = toHandle[i];
			}
			return toReturn;
		}

		char* longToHexBytesStatic(long number, bool isFixedLength, int fixedLength, char padByte)
		{
			if (!isFixedLength)
			{
				wayne::IO::logLn("Warning! It will be no way for you to know the size of the array if you did not assign the size of the byte array explicitly.", true);
			}
			if (fixedLength < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return nullptr;
			}
			std::vector<char> toHandle = longToHexBytes(number, isFixedLength, fixedLength, padByte);
			if (toHandle.size() < (size_t)1)
			{
				wayne::IO::logLn("Your request cannot be completed.");
				return nullptr;
			}
			char* toReturn = new char[toHandle.size()];
			for (size_t i = 0; i < toHandle.size(); i++)
			{
				toReturn[i] = toHandle[i];
			}
			return toReturn;
		}

		char* unsignedIntToHexBytesStatic(unsigned int number, bool isFixedLength, int fixedLength, char padByte)
		{
			if (!isFixedLength)
			{
				wayne::IO::logLn("Warning! It will be no way for you to know the size of the array if you did not assign the size of the byte array explicitly.", true);
			}
			if (fixedLength < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return nullptr;
			}
			std::vector<char> toHandle = unsignedIntToHexBytes(number, isFixedLength, fixedLength, padByte);
			if (toHandle.size() < (size_t)1)
			{
				wayne::IO::logLn("Your request cannot be completed.");
				return nullptr;
			}
			char* toReturn = new char[toHandle.size()];
			for (size_t i = 0; i < toHandle.size(); i++)
			{
				toReturn[i] = toHandle[i];
			}
			return toReturn;
		}

		char* unsignedLongToHexBytesStatic(unsigned long number, bool isFixedLength, int fixedLength, char padByte)
		{
			if (!isFixedLength)
			{
				wayne::IO::logLn("Warning! It will be no way for you to know the size of the array if you did not assign the size of the byte array explicitly.", true);
			}
			if (fixedLength < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return nullptr;
			}
			std::vector<char> toHandle = unsignedLongToHexBytes(number, isFixedLength, fixedLength, padByte);
			if (toHandle.size() < (size_t)1)
			{
				wayne::IO::logLn("Your request cannot be completed.");
				return nullptr;
			}
			char* toReturn = new char[toHandle.size()];
			for (size_t i = 0; i < toHandle.size(); i++)
			{
				toReturn[i] = toHandle[i];
			}
			return toReturn;
		}

		int hexBytesStaticToInt(char* hexBytes, int hexLength, bool isPositive)
		{
			if (hexLength < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return INT_MIN;
			}
			unsigned int accumulator = 0;
			for (int i = hexLength - 1; i >=0; i--)
			{
				unsigned int higherDigitsAccumulator = (unsigned int)hexBytes[i];
				for (int j = 0; j < i; j++)
				{
					higherDigitsAccumulator *= 256;
				}
				accumulator += higherDigitsAccumulator;
			}
			if (isPositive)
			{
				return accumulator;
			}
			else
			{
				return (~accumulator)+1;
			}
		}

		long hexBytesStaticToLong(char* hexBytes, int hexLength, bool isPositive)
		{
			if (hexLength < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return INT_MIN;
			}
			unsigned long accumulator = 0;
			for (int i = hexLength - 1; i >=0; i--)
			{
				unsigned long higherDigitsAccumulator = (unsigned long)hexBytes[i];
				for (int j = 0; j < i; j++)
				{
					higherDigitsAccumulator *= 256;
				}
				accumulator += higherDigitsAccumulator;
			}
			if (isPositive)
			{
				return accumulator;
			}
			else
			{
				return (~accumulator)+1;
			}
		}

		unsigned int unsignedHexBytesStaticToInt(unsigned char* hexBytes, int hexLength)
		{
			if (hexLength < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return INT_MIN;
			}
			unsigned int accumulator = 0;
			for (int i = hexLength - 1; i >=0; i--)
			{
				unsigned int higherDigitsAccumulator = (unsigned int)hexBytes[i];
				for (int j = 0; j < i; j++)
				{
					higherDigitsAccumulator *= 256;
				}
				accumulator += higherDigitsAccumulator;
			}
			return accumulator;
		}

		unsigned long unsignedHexBytesStaticToLong(unsigned char* hexBytes, int hexLength)
		{
			if (hexLength < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return INT_MIN;
			}
			unsigned long accumulator = 0;
			for (int i = hexLength - 1; i >=0; i--)
			{
				unsigned long higherDigitsAccumulator = (unsigned long)hexBytes[i];
				for (int j = 0; j < i; j++)
				{
					higherDigitsAccumulator *= 256;
				}
				accumulator += higherDigitsAccumulator;
			}
			return accumulator;
		}

		int hexBytesToInt(std::vector<char> hexBytes, bool isPositive)
		{
			if (hexBytes.size() < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return INT_MIN;
			}
			unsigned int accumulator = 0;
			std::reverse(hexBytes.begin(), hexBytes.end());
			for (size_t i = 0; i < hexBytes.size(); i++)
			{
				unsigned int higherDigitsAccumulator = (unsigned int)hexBytes[i];
				for (int j = 0; j < (int)i; j++)
				{
					higherDigitsAccumulator *= 256;
				}
				accumulator += higherDigitsAccumulator;
			}
			if (isPositive)
			{
				return accumulator;
			}
			else
			{
				return (~accumulator)+1;
			}
		}

		long hexBytesToLong(std::vector<char> hexBytes, bool isPositive)
		{
			if (hexBytes.size() < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return INT_MIN;
			}
			unsigned long accumulator = 0;
			std::reverse(hexBytes.begin(), hexBytes.end());
			for (size_t i = 0; i < hexBytes.size(); i++)
			{
				unsigned long higherDigitsAccumulator = (unsigned long)hexBytes[i];
				for (int j = 0; j < (int)i; j++)
				{
					higherDigitsAccumulator *= 256;
				}
				accumulator += higherDigitsAccumulator;
			}
			if (isPositive)
			{
				return accumulator;
			}
			else
			{
				return (~accumulator)+1;
			}
		}

		unsigned int unsignedHexBytesToInt(std::vector<char> hexBytes)
		{
			if (hexBytes.size() < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return INT_MIN;
			}
			unsigned int accumulator = 0;
			std::reverse(hexBytes.begin(), hexBytes.end());
			for (size_t i = 0; i < hexBytes.size(); i++)
			{
				unsigned int higherDigitsAccumulator = (unsigned int)hexBytes[i];
				for (int j = 0; j < (int)i; j++)
				{
					higherDigitsAccumulator *= 256;
				}
				accumulator += higherDigitsAccumulator;
			}
			return accumulator;
		}

		unsigned long unsignedHexBytesToLong(std::vector<char> hexBytes)
		{
			if (hexBytes.size() < 1)
			{
				wayne::IO::logLn("Your requested array size cannot be completed.");
				return INT_MIN;
			}
			unsigned long accumulator = 0;
			std::reverse(hexBytes.begin(), hexBytes.end());
			for (size_t i = 0; i < hexBytes.size(); i++)
			{
				unsigned long higherDigitsAccumulator = (unsigned long)hexBytes[i];
				for (int j = 0; j < (int)i; j++)
				{
					higherDigitsAccumulator *= 256;
				}
				accumulator += higherDigitsAccumulator;
			}
			return accumulator;
		}

		unsigned int getOnesComplimentUnsignedInt(int negativeNumber, unsigned int byteLength)
		{
			if (byteLength < 1)
			{
				wayne::IO::logLn("Cannot generate a compliment without receiving byteLength", true);
				return 0;
			}
			unsigned int maxNumber = 1;
			for (int i = 0; i < byteLength; i++)
			{
				maxNumber = maxNumber * 256;
			}
			maxNumber--;
			unsigned int unsignedNegativeNumber = ~negativeNumber;
			if (~unsignedNegativeNumber > maxNumber)
			{
				wayne::IO::logLn("Given number couldn't fit into given byte length", true);
				return 0;
			}
			return maxNumber - (~unsignedNegativeNumber);
		}

		unsigned long getOnesComplimentUnsignedLong(long negativeNumber, unsigned int byteLength)
		{
			if (byteLength < 1)
			{
				wayne::IO::logLn("Cannot generate a compliment without receiving byteLength", true);
				return 0;
			}
			unsigned long maxNumber = 1;
			for (int i = 0; i < byteLength; i++)
			{
				maxNumber = maxNumber * 256;
			}
			maxNumber--;
			unsigned long unsignedNegativeNumber = ~negativeNumber;
			if (~unsignedNegativeNumber > maxNumber)
			{
				wayne::IO::logLn("Given number couldn't fit into given byte length", true);
				return 0;
			}
			return maxNumber - (~unsignedNegativeNumber);
		}

		unsigned int getTwosComplimentUnsignedInt(int negativeNumber, unsigned int byteLength)
		{
			if (byteLength < 1)
			{
				wayne::IO::logLn("Cannot generate a compliment without receiving byteLength", true);
				return 0;
			}
			unsigned int maxNumber = 1;
			for (int i = 0; i < byteLength; i++)
			{
				maxNumber = maxNumber * 256;
			}
			maxNumber--;
			unsigned int unsignedNegativeNumber = ~negativeNumber;
			unsignedNegativeNumber++;
			if (~unsignedNegativeNumber > maxNumber)
			{
				wayne::IO::logLn("Given number couldn't fit into given byte length", true);
				return 0;
			}
			return maxNumber - (~unsignedNegativeNumber);
		}

		unsigned long getTwosComplimentUnsignedLong(long negativeNumber, unsigned int byteLength)
		{
			if (byteLength < 1)
			{
				wayne::IO::logLn("Cannot generate a compliment without receiving byteLength", true);
				return 0;
			}
			unsigned long maxNumber = 1;
			for (int i = 0; i < byteLength; i++)
			{
				maxNumber = maxNumber * 256;
			}
			maxNumber--;
			unsigned long unsignedNegativeNumber = ~negativeNumber;
			unsignedNegativeNumber++;
			if (~unsignedNegativeNumber > maxNumber)
			{
				wayne::IO::logLn("Given number couldn't fit into given byte length", true);
				return 0;
			}
			return maxNumber - (~unsignedNegativeNumber);
		}

	} /* namespace numberUtil */
} /* namespace wayne */
