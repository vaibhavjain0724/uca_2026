#!/bin/bash


file=$1
# sed s/old/new/g 
# g for global
# s to replace stufff
# | can also be the delimeter

# /d for delete
# sed /pattern/d
#deletes lines containing pattern

# -i for inplace editing

#using | as deli
# sed 's|HTTP/1.0|HTTP/1.1|g' $file
# sed '/^#/d' $file

# -E gto use ? and {} like extended features


#  'backup' os necessary in mac not in linux
sed -E -i 'backup' \
    -e 's|HTTP/1.0|HTTP/1.1|g' \
    -e '/^#/d' \
    -e 's|[0-9]{4}-?[0-9]{4}-?[0-9]{4}-?[0-9]{4}|XXXX-XXXX-XXXX-XXXX|g' \
    $file