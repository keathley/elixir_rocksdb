#include <iostream>
#include <assert.h>
#include "rocksdb/db.h"

using namespace std;

int main(int argc, char **argv) {
  rocksdb::DB* db;
  rocksdb::Options options;
  options.create_if_missing = true;
  rocksdb::Status status =
    rocksdb::DB::Open(options, "/tmp/testdb", &db);

  assert(status.ok());


  while(true) {
    string op;
    string key;
    string value;
    rocksdb::Status s;

    cout << "Enter command (GET || PUT)\n";

    cin >> op;
    if (op.empty()) break;

    if (op == "GET") {
      cout << "Enter Key: ";
      cin >> key;
      s = db->Get(rocksdb::ReadOptions(), key, &value);
    } else if (op == "PUT") {
      cout << "Enter Key: ";
      cin >> key;
      cout << "Enter Value: ";
      cin >> value;
      s = db->Put(rocksdb::WriteOptions(), key, value);
    }

    if (s.ok()) {
      cout << "Success:\n" << op << "\nKey: " << key << "\nValue: " << value << "\n";
    } else {
      cout << "Error unknown\n";
    }
  }

  /* std::string value; */

  /* rocksdb::Status s = db->Get(rocksdb::ReadOptions(), key1, &value); */
  /* if(s.ok()) s = db->Put(rocksdb::WriteOptions(), key2, value); */
  /* if(s.ok()) s = db->Delete(rocksdb::WriteOptions(), key1); */

  delete db;

  return 0;
}
