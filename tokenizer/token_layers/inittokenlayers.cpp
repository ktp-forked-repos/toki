#include "inittokenlayers.h"
#include "affixsplitlayer.h"
#include "appendlayer.h"
#include "basicsplitlayer.h"
#include "combinelayer.h"
#include "regexpclassifylayer.h"

bool init_token_layers()
{
	static bool init_done = false;
	if (init_done) return false;

	TokenLayer::register_layer<AffixSplitLayer>("affix_split");
	TokenLayer::register_layer<AppendLayer>("append");
	TokenLayer::register_layer<BasicSplitLayer>("split");
	TokenLayer::register_layer<CombineLayer>("combine");
	TokenLayer::register_layer<RegexpClassifyLayer>("classify_regexp");

	init_done = true;
	return true;
}
