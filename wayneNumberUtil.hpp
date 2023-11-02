/*
 * wayneNumberUtil.hpp
 *
 *  Created on: 2023年10月22日
 *      Author: weich
 */

#ifndef LIB_WAYNENUMBERUTIL_HPP_
#define LIB_WAYNENUMBERUTIL_HPP_
#include <vector>
#include "wayneIO.hpp";

namespace wayne {

	namespace numberUtil {

		enum numberDataLength {
			SHORT_DATA_LENGTH = 2,
			INTEGER_DATA_LENGTH = 4,
			LONG_DATA_LENGTH = 8
		};

		enum numberByteOrder {
			ORDER_DATA_DEFAULT = 0,
			ORDER_DATA_SMALL_ENDIAN = 1,
			ORDER_DATA_BIG_ENDIAN = 2
		};

		template<typename integerType> std::vector<char> numberToBytes(integerType const& number, numberByteOrder numByteOrder = ORDER_DATA_DEFAULT);
		template<typename integerType> char* numberToBytesStatic(integerType const& number, numberByteOrder numByteOrder = ORDER_DATA_DEFAULT);
		template<typename integerType> integerType bytesToNumber(std::vector<char> rawBytes, integerType const& referenceType, numberByteOrder rawByteOrder = ORDER_DATA_DEFAULT);
		template<typename integerType> integerType bytesStaticToNumber(char* rawBytes, integerType const& referenceType, numberByteOrder rawByteOrder = ORDER_DATA_DEFAULT);
		bool isBigEndian();

	} /* namespace numberUtil */
} /* namespace wayne */

#endif /* LIB_WAYNENUMBERUTIL_HPP_ */
