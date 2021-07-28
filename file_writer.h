#ifndef LAB_FILE_WRITER_H
#define LAB_FILE_WRITER_H

void make_csv_file();
void write_on_csv(char type[], int no_of_threads, int member_operations,
                  int insert_operations, int delete_operations, unsigned long time_interval);

#endif //LAB_FILE_WRITER_H
