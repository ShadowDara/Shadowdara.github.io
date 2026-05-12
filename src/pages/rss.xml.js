import rss from '@astrojs/rss';
import { getCollection } from 'astro:content';
import { p } from '../consts';

export async function GET(context) {
	const posts = await getCollection('blog');
	return rss({
		title: p.SITE_TITLE_blog,
		description: p.SITE_DESCRIPTION_blog,
		site: context.site,
		items: posts.map((post) => ({
			...post.data,
			link: `/blog/${post.id}/`,
		})),
	});
}
