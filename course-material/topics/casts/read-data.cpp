std::ifstream input("fat12.img", std::ios::binary);
FAT12 data;

input.read( reinterpret_cast<char*>(&data),
            sizeof(FAT12));

int disk_size = data.bytes_per_sector *
                data.small_number_of_sectors;
