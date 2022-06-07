/* Parse a matches.txt file to determine matching query and database filenames
 *
 * M. lourakis, 2022
 */
#include <vector>
#include <array>
#include <cstring>

int readKeyfiles(const char *keyfiles, std::vector<std::string> &keyfilenames)
{
  FILE *fp;

  /* read the keyfiles */
  if(!(fp=fopen(keyfiles, "r"))){
    fprintf(stderr, "Could not open file %s\n", keyfiles);
    return 1;
  }

  keyfilenames.clear();
  char fname[256];
  while(fgets(fname, 256, fp)){
    /* remove trailing newline */
    if(fname[std::strlen(fname)-1]=='\n') fname[std::strlen(fname)-1]=0;

    keyfilenames.push_back(std::string(fname));
  }

  fclose(fp);
  return 0;
}

// matches: i, j, score*1000
int readMatches(const char *matchfile, std::vector<std::array<int, 3>> &matches)
{
  FILE *fp;

  /* read the matches */
  if(!(fp=fopen(matchfile, "r"))){
    fprintf(stderr, "Could not open file %s\n", matchfile);
    return 1;
  }

  matches.clear();
  char buf[256];
  while(fgets(buf, 256, fp)){
    int i, j;
    float score;
    if(sscanf(buf, "%d%d%f", &i, &j, &score)!=3){
      fprintf(stderr, "Error reading line %s in file %s\n", buf, matchfile);
      return 1;
    }

    matches.push_back(std::array<int, 3>{i, j, (int)(score*1000)});
  }

  fclose(fp);
  return 0;
}

int main(int argc, char **argv)
{
  if(argc!=4){
    fprintf(stderr, "Usage: %s <list.in> <query.in> <matches.in>\n", argv[0]);
    exit(1);
  }

  std::vector<std::string> keyfilenames;
  readKeyfiles(argv[1], keyfilenames);

  std::vector<std::string> queryfilenames;
  readKeyfiles(argv[2], queryfilenames);

  std::vector<std::array<int, 3>> matches;
  readMatches(argv[3], matches);

  // query, match, score
  for(size_t i=0; i<matches.size(); ++i){
    printf("%s  %s \t%d\n", queryfilenames[matches[i][0]].c_str(), keyfilenames[matches[i][1]].c_str(), matches[i][2]);
  }
}
