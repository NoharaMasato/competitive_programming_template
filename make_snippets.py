import json
import codecs
import subprocess

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
        with open('libs/'+file_name, encoding='utf-8') as f:
            flag = False
            for line in f:
                if line[:-1] == "// end":
                    break
                if flag:
                    snippet_content.append(line[:-1])
                if line[:-1] == "// start":
                    flag = True
        snippet["body"] = snippet_content
        snippet["description"] = snippet_meta["description"]
        snippets[name] = snippet

with open("output_snippets.json", 'w', encoding='utf-8') as f:
    json.dump(snippets, f, indent=2, ensure_ascii=False)

subprocess.call(["bash", "mv_snippets.sh"])
