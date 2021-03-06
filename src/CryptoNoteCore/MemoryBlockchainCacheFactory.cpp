// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "MemoryBlockchainCacheFactory.h"

namespace CryptoNote {

MemoryBlockchainCacheFactory::MemoryBlockchainCacheFactory(const std::string& filename, Logging::ILogger& logger):
  filename(filename), logger(logger) {
}

MemoryBlockchainCacheFactory::~MemoryBlockchainCacheFactory() {
}

std::unique_ptr<IBlockchainCache> MemoryBlockchainCacheFactory::createRootBlockchainCache(const Currency& currency) {
  return createBlockchainCache(currency, nullptr, 0);
}

std::unique_ptr<IBlockchainCache> MemoryBlockchainCacheFactory::createBlockchainCache(
    const Currency& currency,
    IBlockchainCache* parent,
    uint32_t startIndex) {

  return std::unique_ptr<IBlockchainCache>(new BlockchainCache(filename, currency, logger, parent, startIndex));
}

} //namespace CryptoNote
