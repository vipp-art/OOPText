# オブジェクトしこう
http://vipper.2ch.net/test/read.cgi/news4vip/1446135338/

上記スレから

※細かいところはサンプル参照

# 設計する範囲
本の情報を何かで入力して、それをどこかに保管する。まで

&gt;&gt;37 の「登録者は何らかの入力を元に本を生成して棚に格納する」を実装する

# 本(の情報)を作る
まずは定義しやすい本クラス(本の情報クラス)を用意する。
中身はひとまず蔵書番号と本のタイトル、機能は特になしでシンプルに以下のように
<pre>
/** 本の情報 */
class Book {
private:
	/** 蔵書番号 */
    int64 id_;
    
    /** 題名 */
    std::string title_;

public:
	/** */
    Book( int64 id, std::string title )
        : id_(id), title_(title)
    {
    }
    
    /** 蔵書番号の取得 */
    int64 id() const { return id_; }

    /** 題名の取得 */
    const std::string& title() const { return title_; }
};
</pre>
シンプルに

# 本を管理する棚をつくる
次に本を格納して管理するクラス。

本を管理するのでプロパティは本のリスト、機能は本の追加を用意することに。

削除等は今はまだ関係ないので、置いておく。
<pre>
/** 蔵書の一括管理用クラス */
class BookDatabase {
private:
	/** 登録されている蔵書 */
	std::vector&lt;Book&gt; books_;
	
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
};
</pre>
おなじくシンプルに。

# 登録クラス
次に棚へ本を登録するクラスを用意する。

プロパティは登録対象の棚を用意し、メソッドで何か入力を受け取ってその棚に登録する仕様で実装してみる。
<pre>
/** 蔵書の情報をDBに登録するクラス */
class BookRegister {
private:
	/** 登録対象のDB */
	BookDatabase* target_;
	
public:
	/**
	 * 登録先を指定して初期化
	 * @param target 登録先
	 */
	BookRegister( BookDatabase* target )
		: target_( target )
	{
	}

	/**
	 * 登録
	 * @param input データの入力
	 */
	void doRegister( /*input*/ )
	{
		// TODO: 入力を用意しないといけない
		int64 id = 0
		std::string title = "";
		
		Book book( id, title );
		target_->add( book );
	}
};
</pre>
まだ入力クラスを作ってないので、その部分はTODOとして未実装のままひとまず置いていて、本の生成とその登録だけを作る。

これを踏まえて次のステップで入力クラスを作成する。
今の実装を見ると入力からは「整数の蔵書番号」と「文字列の題名」の2つを取得できないといけないことがわかる。

# 標準入力から読み込み
まずは標準入力からデータを読み込むクラスを作る。

プロパティに蔵書番号と題名を持つようにして、登録クラスはゲッターを使ってそれを参照するように。
データは別途readメソッド用意してそこで一括で入力してもらうように実装してみる。
<pre>
/** 標準入力から情報を取得する */
class RegisterStandardInputReader {
private:
	/** 蔵書番号 */
	int64 id_;
	
	/** 題名 */
	std::string title_;

	/** 蔵書番号の設定 */
	void id( int64 id )
	{
		id_ = id;
	}
	
	/** 題名を設定 */
	void title( const std::string& title )
	{
		title_ = title;
	}
	
public:
	/** 蔵書番号の取得 */
	int64 id() const { return id_; }
	
	/** 題名の取得 */
	const std::string& title() const { return title_; }

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
</pre>
こんな感じで。

実装内容は上記のとおり、プロパティとそのセッター、ゲッター。
それにコマンドプロンプトで文字を打ってもらうという単純な処理を行うreadメソッド。

# 登録者の方に入れ込む
先ほど作った入力クラスを登録者の方の未実装部分に組み込む。
<pre>
/** 蔵書の情報をDBに登録するクラス */
class BookRegister {
private:
	/** 登録対象のDB */
	BookDatabase* target_;
	
public:
	/**
	 * 登録先を指定して初期化
	 * @param target 登録先
	 */
	BookRegister( BookDatabase* target )
		: target_( target )
	{
	}

	/**
	 * 登録
	 * @param input データの入力
	 */
	void doRegister( RegisterStandardInputReader* input )
	{
		input->read();
		
		int64 id = input->id();
		std::string title = input->title();
		
		Book book( id, title );
		target_->add( book );
	}
};
</pre>
完成。
引数で受け取って中で利用するというこれまた単純な実装。

使ってみるとこんな感じ
<pre>
int main()
{
	// 蔵書管理用DB用意
	BookDatabase database;
	
	// 蔵書登録用システム用意
	BookRegister reg( &database );
	
	// データの入力方法を用意
	RegisterStandardInputReader stdreader;  // 標準入力から読み込み
	
	// 登録
	reg.doRegister( &stdreader );
	
	// 登録された蔵書を表示(テスト用にこっそり追加した)
	database.printAll();
	
	return 0;
}
</pre>
printAllは棚の中身を確認したかったので追加。実装はサンプルを参照。

# 標準入力なんて古い。時代はiniファイル
作ってて、標準入力なんて無いわ。大正義iniファイルにしようと思い立ったのでそれも用意する事に。
基本部分はさっきの標準入力から流用できるが、ファイルの指定や読み込み方法が違うのでそこだけ変更したクラスを用意。
<pre>
/** 標準入力から情報を取得する */
class RegisterIniFileReader {
private:
	/** ファイル名 */
	std::string file_;

	/** 蔵書番号 */
	int64 id_;
	
	/** 題名 */
	std::string title_;

	/** 蔵書番号の設定 */
	void id( int64 id )
	{
		id_ = id;
	}
	
	/** 題名を設定 */
	void title( const std::string& title )
	{
		title_ = title;
	}
	
public:
	/**
	 * iniファイルを指定して初期化
	 * @param filename iniファイル名
	 */
	RegisterIniFileReader( std::string filename ) : file_(filename) {
	}

	/** 蔵書番号の取得 */
	int64 id() const { return id_; }
	
	/** 題名の取得 */
	const std::string& title() const { return title_; }

	/** 読み込み */
	virtual void read() {
		int64 id;
		std::string title;

		std::cout << "ファイルから蔵書を登録します。" << std::endl;
		
		<strong>/* 長いので中略 */</strong>
		
		this->id( id );
		this->title( title );
	}
};
</pre>
という感じ。
変更点は変数の追加、コンストラクタでの変数の指定、readの変更の3点。

readの中身は大幅に違うものの、他の部分、特に登録者から見たふるまいに特に違いがない。

# 登録者をiniファイル用に追加
せっかく作ったので登録者の方に追加。
前述のとおり、ふるまいに特に違いが無いためソースをいじる必要がほぼない。
<pre>
/** 蔵書の情報をDBに登録するクラス */
class BookRegister {
private:
	/** 登録対象のDB */
	BookDatabase* target_;
	
public:
	/**
	 * 登録先を指定して初期化
	 * @param target 登録先
	 */
	BookRegister( BookDatabase* target )
		: target_( target )
	{
	}

	/**
	 * 登録
	 * @param input データの入力
	 */
	void doRegister( RegisterStandardInputReader* input )
	{
		input->read();
		
		int64 id = input->id();
		std::string title = input->title();
		
		Book book( id, title );
		target_->add( book );
	}

	/**
	 * 登録
	 * @param input データの入力
	 */
	void doRegister( RegisterIniFileReader* input )
	{
		input->read();
		
		int64 id = input->id();
		std::string title = input->title();
		
		Book book( id, title );
		target_->add( book );
	}
};
</pre>
というわけで、コピペでオーバーロードを追加。
引数の型が違うだけでまったく同じ処理。

使い方は同様に
<pre>
int main()
{
	// 蔵書管理用DB用意
	BookDatabase database;
	
	// 蔵書登録用システム用意
	BookRegister reg( &database );
	
	// データの入力方法を用意
	RegisterIniFileReader fileReader( "data/book.ini" );  // iniファイルから読み込み
	
	// 登録
	reg.doRegister( &fileReader );
	
	// 登録された蔵書を表示
	database.printAll();
	
	return 0;
}
</pre>
こうなる。

ここまで行けば気づくはずだけど、「引数の型以外まったく同じ中身のdoRegisterメソッド」に、「read以外ほぼ同じ中身のクラス2つ」…これはとても無駄

本の情報に「著者」が追加されたりして、入力で取り出す情報が増えたら登録者のメソッド2つに、各クラスのメンバ変数追加して、ゲッター用意して…と入力のクラスの数だけどんどん変更箇所が膨らんでいく。

というわけで、共通部分をくくりだして抽象化する。

# 2つのクラスの共通点を考える
RegisterIniFileReaderとRegisterStandardInputReaderの共通点は
- 蔵書番号idと題名titleというプロパティを持っている
- 同プロパティのゲッターが公開されている
- readメソッドでプロパティを設定している(設定方法は違う)

となる。

これを総合して親クラスを定義すると
<pre>
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
</pre>
こうなる。
共通のプロパティであるidとtitleは親クラスが持つ。
readは名前だけ用意して実装は子クラスに任せる。
(こうして親クラスで名前だけ用意することで、登録者クラスは引数の入力クラスが確実にreadメソッドを実装していることを知ることが出来る。
 子クラスで実装していないとコンパイルエラーが出てそもそもexeが作れない。)

これを踏まえて子クラスは
<pre>
/** 標準入力から情報を取得する */
class RegisterStandardInputReader : public BaseRegisterReader { <strong>// 継承する!</strong>

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
</pre>
<pre>
/** iniファイルからデータを登録するクラス */
class RegisterIniFileReader : public BaseRegisterReader { <strong>// 継承する！</strong>

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
		
		<strong>/* 長いので中略 */</strong>
		
		this->id( id );
		this->title( title );
	}
};
</pre>
こうなる。
両方Baseクラスをpublic継承し、標準入力の方はreadの実装のみを行う。
iniファイルの方は共通点ではなかった、「ファイル名を表すメンバ変数」とその設定を残して、あとはreadの実装のみを行っている。


抽象化されたのでもちろん使う側の登録者にも変化が…

<pre>
/** 蔵書の情報をDBに登録するクラス */
class BookRegister {
private:
	/** 登録対象のDB */
	BookDatabase* target_;
	
public:
	/**
	 * 登録先を指定して初期化
	 * @param target 登録先
	 */
	BookRegister( BookDatabase* target )
		: target_( target )
	{
	}

	/**
	 * 登録
	 * @param input データの入力
	 */
	void doRegister( BaseRegisterReader* input )
	{
		input->read();
		
		int64 id = input->id();
		std::string title = input->title();
		
		Book book( id, title );
		target_->add( book );
	}
};
</pre>
それぞれ用に2つ用意していたメソッドは一本化され、引数は親クラスのものに。

使い方はこうなる
<pre>
int main()
{
	// 蔵書管理用DB用意
	BookDatabase database;
	
	// 蔵書登録用システム用意
	BookRegister reg( &database );
	
	// データの入力方法を用意
	RegisterStandardInputReader stdreader;                // 標準入力から読み込み
	RegisterIniFileReader fileReader( "data/book.ini" );  // iniファイルから読み込み
	
	// 登録処理
	reg.doRegister( &fileReader ); // iniファイル
	reg.doRegister( &stdreader );  // 標準入力
	
	// 登録された蔵書を表示
	database.printAll();
	
	return 0;
}
</pre>
こんな感じ。
