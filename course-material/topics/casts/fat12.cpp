struct FAT12 {
  uint8_t    bootstrap[3];
  uint8_t    os[8];
  uint16_t   bytes_per_sector;
  uint8_t    sectors_per_cluster;
  uint16_t   reserved_sectors;
  uint8_t    number_of_fats;
  uint16_t   number_of_root_entries;
  uint16_t   small_number_of_sectors;
  // ...
};
