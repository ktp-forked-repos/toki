#ifndef LAYERTOKENIZER_H
#define LAYERTOKENIZER_H

#include "tokenizer.h"

class TokenLayer;

#include <boost/scoped_ptr.hpp>

class LayerTokenizer : public Tokenizer
{
public:
	/**
	 * Constructor.
	 * @see Tokenizer::Tokenizer
	 */
	LayerTokenizer(const Config::Node& cfg = Config::Default());

	/**
	 * Constructor shorthand -- start with the given UnicodeSource, and take
	 * ownership
	 * @see Tokenizer::Tokenizer
	 */
	LayerTokenizer(UnicodeSource* input, const Config::Node& cfg = Config::Default());

	/**
	 * Constructor shorthand -- start with the given UnicodeSource as a shared
	 * pointer.
	 * @see Tokenizer::Tokenizer
	 */
	LayerTokenizer(boost::shared_ptr<UnicodeSource> input, const Config::Node& cfg = Config::Default());

	/**
	 * Constructor shorthand -- start with the given std::istream. Note no
	 * ownership is taken and the stream must live long enough.
	 * @see Tokenizer::Tokenizer
	 */
	LayerTokenizer(std::istream& is, const Config::Node& cfg = Config::Default());

	/**
	 * Constructor shorthand -- start with the given UnicodeString, which is
	 * copied.
	 * @see Tokenizer::Tokenizer
	 */
	LayerTokenizer(const UnicodeString& s, const Config::Node& cfg = Config::Default());

	/**
	 * Destructor
	 */
	~LayerTokenizer();

	/**
	 * Apply configuraton
	 */
	void apply_configuration(const Config::Node& cfg);

	/// TokenSource override
	void newInputSource();

	/// TokenSource override
	void reset();

	/// TokenSource override
	Token* getNextToken();

private:
	/// The underlying input token source for the first layer
	boost::scoped_ptr<Tokenizer> input_tokenizer_;

	/// The token procesing layers
	std::vector<TokenLayer*> layers_;
};

#endif // LAYERTOKENIZER_H
