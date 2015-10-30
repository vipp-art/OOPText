#pragma once
#include <string>
#include "Types.h"

/** 登録する際の情報の取得システムの基底 */
class IReader
{
public:
	virtual void read() =0;
	
	/** 指定のタグを64ビット整数で取得 */
	virtual int64 getInt64( std::string tag ) =0;

	/** 指定のタグを文字列で取得 */
	virtual std::string getText( std::string tag ) =0;
	
protected:
	
	/** 継承専用 */
	IReader() {}
	
	/** 継承専用 */
	virtual ~IReader() {}
};
