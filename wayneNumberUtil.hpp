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
			SHORT_LENGTH = 2,
			INTEGER_LENGTH = 4,
			LONG_LENGTH = 8
		};

		template<typename integerType> std::vector<char> numberToBytes(integerType const& number, bool forceBigEndian=false);
		template<typename integerType> char* numberToBytesStatic(integerType const& number, bool forceBigEndian=false);
		template<typename integerType> integerType bytesToNumber(std::vector<char> rawBytes, integerType const& referenceType, bool rawIsBigEndian=false);
		template<typename integerType> integerType bytesStaticToNumber(char* rawBytes, integerType const& referenceType, bool rawIsBigEndian=false);
		bool isBigEndian();

	} /* namespace numberUtil */
} /* namespace wayne */

#endif /* LIB_WAYNENUMBERUTIL_HPP_ */
