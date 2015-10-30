#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include"BaseRegisterReader.hpp"


/** iniファイルからデータを登録するクラス */
class RegisterIniFileReader : public BaseRegisterReader {

private:
	/** ファイル名 */
	std::string file_;

public:
	
	/**
	 * iniファイルを指定して初期化
	 * @param filename iniファイル名
	 */
	RegisterIniFileReader( std::string filename ) : file_(filename) {
	}
	
	/** */
	virtual ~RegisterIniFileReader() {}
	
	/** ファイル解析 */
	virtual void read() {
		std::cout << "ファイルから蔵書を登録します。" << std::endl;
		
		int64 id;
		std::string title;
		
		std::ifstream in( file_ );
		
		// 適当にiniファイルを解析する
		while ( in.good() ) {
			std::string line;
			in >> line;
			
			// #や空白から始まる行と空行は無視
			if ( line.at( 0 ) == '#' ) { continue; }
			if ( line.at( 0 ) == ' ' ) { continue; }
			if ( line.at( 0 ) == '\t' ) { continue; }
			if ( line.empty() ) { continue; }
			

			std::stringstream buffer;

			int i;
			int length = line.length();
			for ( i = 0; i < length; ++i ) {
				char c = line.at( i );
				if ( c == '=' ) {
					break;
				}
				if( c == ' ' || c == '\t' ) {
					continue;
				}
				buffer << c;
			}
			std::string tag = buffer.str();
			std::string value = trim( line.substr( i ) );
			
			if ( tag == "id" ) {
				id = std::stoll( value );
				if ( !title.empty() ) { break; }
			} else if ( tag == "title" ) {
				title = value;
				if ( id != 0 ) { break; }
			}
			
		}
		
		
		this->id( id );
		this->title( title );
	}

private:
	
	/**
	 * 文字列の前後の空白と=と#を削除
	 */
	static std::string trim( const std::string& s ) {
		int left, right;
		int length = s.length();
		
		for ( left = 0; left < length; ++left ) {
			char c = s.at( left );
			switch ( c ) {
				case ' ':
				case '\t':
				case '=':
				case '#':
					continue;
			}
			break;
		}
		for ( right = length - 1; right > left; --right ) {
			char c = s.at( right );
			switch ( c ) {
				case ' ':
				case '\t':
				case '=':
				case '#':
					continue;
			}
			break;
		}
		return s.substr( left, right - left + 1 );
	}
};
