set -e

SCRIPT_DIR=$(dirname $0)
src_dir=$SCRIPT_DIR/../dartcv
include_dir=$SCRIPT_DIR/../include
if [ ! -d $include_dir ] || [ -z "$( ls -A $include_dir )" ]; then
  mkdir -p $include_dir
  find $src_dir -type f -name '*.h' -print0 | xargs -0 -I {} /bin/cp {} $include_dir
  find $include_dir -type f \( -path '*.h' \) -print0 | xargs -0 -L1 sed -E -i'.dartcv_bak' 's;#include "dartcv/core/(.*)";#include "\1";g'
  find $include_dir -type f -name '*.dartcv_bak' -print0 | xargs -0 rm
fi
