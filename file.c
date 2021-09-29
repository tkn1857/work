#include "file.h"

int read_mask_file(char *mask_file)
{
  FILE *read_mask_fp;
  unsigned char mask_buf[8192];
  int count_mask_bytes = 0;
  int ch;
  int write_errors = 0;

  *(int *)mask_buf = USER_SPACE_DATA_TYPE;
  count_mask_bytes = 4;

  if ((read_mask_fp = fopen(mask_file, "rb")) == NULL)
  {
    //   DLT_LOG(diag,DLT_LOG_ERROR,DLT_STRING("Open logmask-file failed."));
    return -1;
  }

  //  DLT_LOG(diag,DLT_LOG_INFO,DLT_STRING("mask file opened: "),DLT_STRING(mask_file));

  while (1)
  {
    ch = fgetc(read_mask_fp);
    if (ch == EOF)
    {
      //    DLT_LOG(diag,DLT_LOG_INFO,DLT_STRING("mask_file EOF reached"));
      break;
    }

    mask_buf[count_mask_bytes] = ch;
    //DLT_LOG(diag,DLT_LOG_INFO,DLT_STRING("Char added to mask_buf. count_mask_bytes: "),DLT_INT(count_mask_bytes));
    if (mask_buf[count_mask_bytes] == CONTROL_CHAR)
    {
      //   write_errors += diag_send_data(mask_buf, count_mask_bytes + 1);
      write_errors += 0;

      *(int *)mask_buf = USER_SPACE_DATA_TYPE;
      count_mask_bytes = 4;
    }
    else
    {
      count_mask_bytes++;
    }
  }

  fclose(read_mask_fp);

  if (write_errors > 0)
  {
    //   DLT_LOG(diag,DLT_LOG_INFO,DLT_STRING("Send logmask to modem failed."));
    return -1;
  }
  //  DLT_LOG(diag,DLT_LOG_INFO,DLT_STRING("Send logmask to modem succeeded."));
  return 0;
}