#pragma once
#include <iostream>
#include <string>
#include"IReader.hpp"


/** 標準入力から情報を取得する */
class StandardInputReader : public IReader {

public:
	/** */
	virtual ~StandardInputReader() {}
	
	/** 事前読み込み */
	virtual void read()
	{
		std::cout << "標準入力から蔵書を登録します。" << std::endl;
	}
	
	/** 指定のタグを64ビット整数で取得 */
	virtual int64 getInt64( std::string tag )
	{
		return std::stoll( getText( tag ) );
	}

	/** 指定のタグを文字列で取得 */
	virtual std::string getText( std::string tag )
	{
		std::string result;
		std::cout << tag << ':' << std::flush;
		std::cin >> result;
		return result;
	}

};
