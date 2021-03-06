#pragma once
#include <iostream>
#include <string>
#include"BaseRegisterReader.hpp"


/** 標準入力から情報を取得する */
class RegisterStandardInputReader : public BaseRegisterReader {

public:
	/** */
	virtual ~RegisterStandardInputReader() {}
	
	/** 読み込み */
	virtual void read() {
		int64 id;
		std::string title;

		std::cout << "蔵書の登録をします。" << std::endl;

		std::cout << "蔵書番号を入力:" << std::flush;
		std::cin >> id;
		std::cout << std::endl;

		std::cout << "題名を入力:" << std::flush;
		std::cin >> title;
		std::cout << std::endl;
		
		this->id( id );
		this->title( title );
	}

};
