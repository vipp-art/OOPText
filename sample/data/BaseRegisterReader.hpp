#pragma once
#include <string>
#include "Types.h"

/** 登録する際の情報の取得システムの基底 */
class BaseRegisterReader
{
private:
	/** 蔵書番号 */
	int64 id_;
	
	/** 題名 */
	std::string title_;
	
public:
	/** 読み込む処理 */
	virtual void read() =0;
	
	/** 蔵書番号の取得 */
	int64 id() const { return id_; }
	
	/** 題名の取得 */
	const std::string& title() const { return title_; }
	
protected:
	
	/** 継承専用 */
	BaseRegisterReader() {}
	
	/** 継承専用 */
	virtual ~BaseRegisterReader() {}
	
	/** 継承専用：蔵書番号の設定 */
	void id( int64 id )
	{
		id_ = id;
	}
	
	/** 継承専用：題名を設定 */
	void title( const std::string& title )
	{
		title_ = title;
	}
};
