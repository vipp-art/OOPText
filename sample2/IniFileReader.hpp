#pragma once
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include"IReader.hpp"


/** ini�t�@�C������f�[�^��o�^����N���X */
class IniFileReader : public IReader {

private:
	/** �t�@�C���� */
	std::string file_;

	/** �f�[�^ */
	std::map<std::string, std::string> datas_;

public:
	
	/**
	 * ini�t�@�C�����w�肵�ď�����
	 * @param filename ini�t�@�C����
	 */
	IniFileReader( std::string filename ) : file_(filename) {
	}
	
	/** */
	virtual ~IniFileReader() {}
	
	
	/** �w��̃^�O��64�r�b�g�����Ŏ擾 */
	virtual int64 getInt64( std::string tag )
	{
		return std::stoll( getText( tag ) );
	}

	/** �w��̃^�O�𕶎���Ŏ擾 */
	virtual std::string getText( std::string tag )
	{
		return datas_[tag];
	}
	
	/** �t�@�C����� */
	virtual void read() {
		std::cout << "�t�@�C�����瑠����o�^���܂��B" << std::endl;
		
		int64 id;
		std::string title;
		
		std::ifstream in( file_ );
		
		// �K����ini�t�@�C������͂���
		while ( in.good() ) {
			std::string line;
			in >> line;
			
			// #��󔒂���n�܂�s�Ƌ�s�͖���
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
	 * ������̑O��̋󔒂�=��#���폜
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
