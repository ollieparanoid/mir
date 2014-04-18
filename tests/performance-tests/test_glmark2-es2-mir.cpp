#include <gtest/gtest.h>
#include <stdlib.h>


#include <boost/regex.hpp>
#include <iostream>
#include <fstream>
#include <string>

class GLMark2Test : public ::testing::Test
{
protected:
  enum ResultFileType {RAW, JSON};
  virtual void RunGLMark2(const char *output_filename, ResultFileType file_type)
  {
    boost::cmatch matches;
    boost::regex re_glmark2_score(".*glmark2\\s+Score:\\s+(\\d+).*");
    FILE *in;
    const char *cmd = "glmark2-es2-mir --fullscreen";
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    std::ofstream glmark2_output;

    ASSERT_TRUE((in = popen(cmd, "r")));
    
    glmark2_output.open(output_filename);
    while((read = getline(&line, &len, in)) != -1)
    {
      if(file_type == RAW)
        glmark2_output << line; 
      else if(file_type == JSON)
      {
        if(boost::regex_match(line, matches, re_glmark2_score))
        {
          std::string json =  "{";
            json += "'benchmark_name':'glmark2-es2-mir'";
            json += ",";
            json += "'score':'" + matches[1] + "'";
            json += "}";
          glmark2_output << json;
        }
      }
    }
    
    free(line);
    fclose(in);
    glmark2_output.close();
  }
};

TEST_F(GLMark2Test, benchmark_fullscreen_default)
{
  RunGLMark2("glmark2_fullscreen_default.json", JSON);
}
