#pragma once
#include <iostream>
#include <vector>
#include "Book.hpp"

/** 蔵書の一括管理用クラス */
class BookDatabase {
private:
	/** 登録されている蔵書 */
	std::vector<Book> books_;
	
public:
	/** */
	BookDatabase() : books_()
	{
	}
	
	/**
	 * 蔵書追加
	 * @param book 追加する本の情報
	 */
	void add( const Book& book )
	{
		books_.push_back( book );
	}
	
	/**
	 * 登録されてる情報を一覧
	 */
	void printAll() const
	{
		std::cout << "蔵書一覧" << std::endl;
		for ( auto book : books_ ) {
			std::cout << '\t' << book.id() << " : " << book.title() << std::endl;
		}
	}
};
