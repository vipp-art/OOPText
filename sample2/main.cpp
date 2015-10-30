#include "Book.hpp"
#include "BookDatabase.hpp"
#include "BookRegister.hpp"
#include "StandardInputReader.hpp"
#include "IniFileReader.hpp"

int main()
{
	// 蔵書管理用DB用意
	BookDatabase database;
	
	// 蔵書登録用システム用意
	BookRegister reg( &database );
	
	// データの入力方法を用意
	StandardInputReader stdreader;					// 標準入力から読み込み
	IniFileReader fileReader( "data/book.ini" );	// iniファイルから読み込み
	
	// 登録
	reg.doRegister( &fileReader );
	reg.doRegister( &stdreader );
	
	// 登録された蔵書を表示
	database.printAll();
	
	return 0;
}
