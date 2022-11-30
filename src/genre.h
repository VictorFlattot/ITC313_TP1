//
// Created by Shadow on 30/11/2022.
//

#pragma once

enum class Genre {
    Drama, Fable, FairyTale, Fantasy, Fiction, FictionInVerse, Folklore,
    HistoricalFiction, Horror, Humor, Legend, Mystery, Mythology, Poetry,
    RealisticFiction, ScienceFiction, ShortStory, TallTale, Biography, Essay,
    NarrativeNonFiction, NonFiction, Speech, Unspecified
};

std::array<std::string, 24> const genre_str = {
        "Drama", "Fable", "FairyTale", "Fantasy", "Fiction", "FictionInVerse", "Folklore",
        "HistoricalFiction", "Horror", "Humor", "Legend", "Mystery", "Mythology", "Poetry",
        "RealisticFiction", "ScienceFiction", "ShortStory", "TallTale", "Biography", "Essay",
        "NarrativeNonFiction", "NonFiction", "Speech", "Unspecified"
};


