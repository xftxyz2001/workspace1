// https://github.com/jehna/humanify src\plugins\openai\openai-rename.ts

import OpenAI from "openai";
import { visitAllIdentifiers } from "../local-llm-rename/visit-all-identifiers.js";
import { showPercentage } from "../../progress.js";
import { verbose } from "../../verbose.js";

const nameMap = {
  x: "y"
};

function showRenamePrompt(name, surroundingCode, model) {
  let renamePrompt = toRenamePrompt(name, surroundingCode, model);
  let renamePromptJSON = JSON.parse(JSON.stringify(renamePrompt));
  delete renamePromptJSON["model"];
  console.log(JSON.stringify(renamePromptJSON));
}

export function openaiRename({
  apiKey,
  baseURL,
  model,
  contextWindowSize
}: {
  apiKey: string;
  baseURL: string;
  model: string;
  contextWindowSize: number;
}) {
  // const client = new OpenAI({ apiKey, baseURL });

  return async (code: string): Promise<string> => {
    return await visitAllIdentifiers(
      code,
      async (name, surroundingCode) => {
        verbose.log(`Renaming ${name}`);
        verbose.log("Context: ", surroundingCode);

        // const response = await client.chat.completions.create(
        //   toRenamePrompt(name, surroundingCode, model)
        // );
        // const result = response.choices[0].message?.content;
        // if (!result) {
        //   throw new Error("Failed to rename", { cause: response });
        // }
        // const renamed = JSON.parse(result).newName;

        // 运行 npm run start openai input.js > req.txt 手动请求每行结果将映射保存到nameMap中
        showRenamePrompt(name, surroundingCode, model);
        const renamed = (nameMap as Record<string, string>)[name] || name;

        verbose.log(`Renamed to ${renamed}`);
        return renamed;
      },
      contextWindowSize,
      showPercentage
    );
  };
}

function toRenamePrompt(
  name: string,
  surroundingCode: string,
  model: string
): OpenAI.Chat.Completions.ChatCompletionCreateParamsNonStreaming {
  return {
    model,
    messages: [
      {
        role: "system",
        content: `Rename Javascript variables/function \`${name}\` to have descriptive name based on their usage in the code."`
      },
      {
        role: "user",
        content: surroundingCode
      }
    ],
    response_format: {
      type: "json_schema",
      json_schema: {
        strict: true,
        name: "rename",
        schema: {
          type: "object",
          properties: {
            newName: {
              type: "string",
              description: `The new name for the variable/function called \`${name}\``
            }
          },
          required: ["newName"],
          additionalProperties: false
        }
      }
    }
  };
}
