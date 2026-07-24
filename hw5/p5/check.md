余绵峯，计52，2024010147


## 正确性问题
- 在removeByArtist函数里面，当songs,erase(it)发生的时候，it迭代器就已经失效了，++it就会发生错误
- 在generateRecommendations函数里面, 当触发songs.push_back的时候，for(auto& song : songs)需要多循环新加入的song, 继续触发songs.push_back, 继续多循环，不断重复出现死循环。
- 在generateRecommmendations函数里面，如果song是一个PremiumSong，则(*song)会发生对象切片，发生错误。
- 在importSong函数里面同时用raw原始指针生成了两个shared_ptr, 会导致这个原始指针被delete两次，发生错误。
- 在transferSong当中, std::move(song)之后song已经变成了空指针，紧接着的song-display()会发生错误
- getPlayCount函数是const函数，但是playCount[title]如果key不存在时会自动插入0，是非const的，所以会发生错误。

## 运行效率
- Song类的构造函数可以改为(const string& t,const string& a, int d)，避免值拷贝。 提高运行效率。 PremiumSong同理