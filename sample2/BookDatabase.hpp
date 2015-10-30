#pragma once
#include <iostream>
#include <vector>
#include "Book.hpp"

/** ‘ ‘‚ÌˆêŠ‡ŠÇ——pƒNƒ‰ƒX */
class BookDatabase {
private:
	/** “o˜^‚³‚ê‚Ä‚¢‚é‘ ‘ */
	std::vector<Book> books_;
	
public:
	/** */
	BookDatabase() : books_()
	{
	}
	
	/**
	 * ‘ ‘’Ç‰Á
	 * @param book ’Ç‰Á‚·‚é–{‚Ìî•ñ
	 */
	void add( const Book& book )
	{
		books_.push_back( book );
	}
	
	/**
	 * “o˜^‚³‚ê‚Ä‚éî•ñ‚ğˆê——
	 */
	void printAll() const
	{
		std::cout << "‘ ‘ˆê——" << std::endl;
		for ( auto book : books_ ) {
			std::cout << '\t' << book.id() << " : " << book.title() << std::endl;
		}
	}
};
