#pragma once
#include <iostream>
#include <vector>
#include "Book.hpp"

/** �����̈ꊇ�Ǘ��p�N���X */
class BookDatabase {
private:
	/** �o�^����Ă��鑠�� */
	std::vector<Book> books_;
	
public:
	/** */
	BookDatabase() : books_()
	{
	}
	
	/**
	 * �����ǉ�
	 * @param book �ǉ�����{�̏��
	 */
	void add( const Book& book )
	{
		books_.push_back( book );
	}
	
	/**
	 * �o�^����Ă�����ꗗ
	 */
	void printAll() const
	{
		std::cout << "�����ꗗ" << std::endl;
		for ( auto book : books_ ) {
			std::cout << '\t' << book.id() << " : " << book.title() << std::endl;
		}
	}
};
