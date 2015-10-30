#pragma once
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include"IReader.hpp"


/** iniファイルからデータを登録するクラス */
class IniFileReader : public IReader {

private:
	/** ファイル名 */
	std::string file_;

	/** データ */
	std::map<std::string, std::string> datas_;

public:
	
	/**
	 * iniファイルを指定して初期化
	 * @param filename iniファイル名
	 */
	IniFileReader( std::string filename ) : file_(filename) {
	}
	
	/** */
	virtual ~IniFileReader() {}
	
	
	/** 指定のタグを64ビット整数で取得 */
	virtual int64 getInt64( std::string tag )
	{
		return std::stoll( getText( tag ) );
	}

	/** 指定のタグを文字列で取得 */
	virtual std::string getText( std::string tag )
	{
		return datas_[tag];
	}
	
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
			if ( line.empty() ) { continue; }
			if ( line.at( 0 ) == '#' ) { continue; }
			if ( line.at( 0 ) == ' ' ) { continue; }
			if ( line.at( 0 ) == '\t' ) { continue; }
			

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
			
			if ( tag.empty() ) {
				continue;
			}
			
			std::string value = trim( line.substr( i ) );
			datas_[tag] = value;
		}
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
		int l = right - left + 1;
		if ( l <= 0 ) {
			return "";
		}
		if ( l + left > length ) {
			l = length - left;
		}
		return s.substr( left, l );
	}
};
