import json
import codecs

snippets = {}
with open('snippets.json') as f:
    df = json.load(f)
    snippets_meta = df["snippets"]
    for snippet_meta in snippets_meta:
        snippet = {}
        name = snippet_meta["name"]
        file_name = snippet_meta["snippets_file"]
        snippet["prefix"] = snippet_meta["prefix"]
        snippet_content = []
        with open('snippets/'+file_name, encoding='utf-8') as f:
            for line in f:
                snippet_content.append(line[:-1])
                print(line[:-1])
        snippet["body"] = snippet_content
        snippet["description"] = snippet_meta["description"]
        snippets[name] = snippet
with open('snippets_output.json', 'w', encoding='utf-8') as f:
    json.dump(snippets, f, indent=2, ensure_ascii=False)
# file = codecs.open("snippets_output.json", "w", "utf-8")
# file.write(snippets)
# file.close()